/** @file
	イベントスクリプト関連の定義.
*/

#ifndef _ESCRIPT_H__
#define _ESCRIPT_H__

#define	ESC_OBJSADDR			0x80028000							
#define	ESC_OBJDSIZEMAX			0x100000							
#define ESC_FLAG_MAX			1024								

// フラグ番号
#define	_MONTH		0	///< 月
#define	_DAY		1	///< 日
#define	_TIME		2	///< 時間
#define	_EVENT_NEXT	3	///< 次のイベント
#define	_EVENT_END	4	///< イベント終了
#define	_DEFAULT_NAME	5	///< 名前デフォルト
#define	_CALENDER_SKIP	6	
#define	_CLOCK_TIME		7	///< 時計

#define	_DEBUG_CALL		9	

#define ESC_SetFlag( N, D )		ESC_FlagBuf[ ( N ) ] = ( D )		///< フラグに値を代入
#define ESC_GetFlag( N )		ESC_FlagBuf[ ( N ) ]				///< フラグ値を取得

/**
	命令に必要なパラメータを読み込み、命令を実行.
	@param opr 命令コード
*/
extern int  ESC_OprControl( int opr );

/**
	フラグを初期化.
*/
extern void ESC_InitFlag( void );


extern void ESC_InitEOprFlag( void );


extern int	ESC_FlagBuf[ ESC_FLAG_MAX ]; ///< ゲーム個別セーブフラグ
extern int	ESC_GameFlagBuf[ ESC_FLAG_MAX ]; ///< ゲーム全体フラグ

extern void SetVoiceDialog( int flag );
extern void AddVoiceDialogMes( char *mes, ...);

extern void ESC_SetDrawFlag( void );
extern void ESC_CodeCheck(void);


#define	SCRIPT_BLOCK_MAX		256 ///< スクリプトブロック総数


/// スクリプトヘッダ
typedef struct {
	short			h1, h2;
	long			Fsize; ///< ファイルサイズ
	unsigned long	BlockAddres[ SCRIPT_BLOCK_MAX ]; ///< スクリプトブロックのアドレス
} SCRIPT_HEADER;

enum {
	OPRS_START = 0,
	OPRS_END,

	OPRS_MOVR,
	OPRS_MOVV,
	OPRS_SWAP,
	OPRS_RAND,

	OPRS_IFR,
	OPRS_IFV,
	OPRS_IFELSER,
	OPRS_IFELSEV,

	OPRS_LOOP,
	OPRS_GOTO,

	OPRS_INC,
	OPRS_DEC,
	OPRS_NOT,
	OPRS_NEG,

	OPRS_ADDR,
	OPRS_ADDV,
	OPRS_SUBR,
	OPRS_SUBV,
	OPRS_MULR,
	OPRS_MULV,
	OPRS_DIVR,
	OPRS_DIVV,
	OPRS_MODR,
	OPRS_MODV,
	OPRS_ANDR,
	OPRS_ANDV,
	OPRS_ORR,
	OPRS_ORV,
	OPRS_XORR,
	OPRS_XORV,

	OPRS_CALC,

	OPRS_PUSHA,
	OPRS_POPA,

	OPRS_CALL,
	OPRS_RET,

	OPRS_WAIT,
	OPRS_TWAIT,
	OPRS_RUN,

	OPRS_SLOAD,
	OPRS_TSTART,

	OPRS_OPREND,
};

extern char ScrCodeList[64][32];

/**
	スクリプトデータパッケージのあるディレクトリを指定
	@param pac_dir ディレクトリ名
*/
extern void EXEC_SetPackDir( char *pac_dir );

#define	MAIN_SCRIPT				0

#define SCCODE_NOOPR			0					///< 命令なし
#define SCCODE_RUN				1					///< 実行中
#define SCCODE_WAIT_WAIT		2					///< フレーム数単位のウェイト中
#define SCCODE_WAIT_TWAIT		3					///< ミリ秒単位のウェイト中
#define SCCODE_WAIT_SLOAD		4					///< スクリプト読み込み中
#define SCCODE_WAIT_DEBUG		0xFF				

#define REGISTER_MAX			50					///< レジスタ総数
#define	STACK_MAX				512					///< スタック総数
#define	TASK_MAX				8					///< タスク総数（不使用）
enum{												
	SCRMODE_EVENT,
	SCRMODE_MAX
};

// EXEC_OprCalc() で用いるデータ要素内容列挙値
enum {
	FACT_VAL = 0, ///< 値
	FACT_REG, ///< レジスタ番号
	FACT_CLC, ///< 演算子
	FACT_END, ///< 終了
};

enum {
	CALL_SMALL = 0,
	CALL_ESMALL,
	CALL_LARGE,
	CALL_ELARGE,
	CALL_EQUAL,
	CALL_NEQUAL,

	CALL_ADD,
	CALL_SUB,
	CALL_MUL,
	CALL_DIV,
	CALL_MOD,
};


/// スクリプトデータ情報構造体
typedef struct {									
	DWORD		BlockAddres[SCRIPT_BLOCK_MAX];		///< スクリプトブロックのアドレス
	long		sp_buf[STACK_MAX];					///< スタック
	long		reg[REGISTER_MAX];					///< レジスタ
	DWORD		pc;									///< プログラムカウンタ
	DWORD		sp;									///< スタックポインタ
	DWORD		WaitCounter;						///< ウェイトフレーム数計測カウンタ
	DWORD		WaitEnd;							///< ウェイトフレーム数
	DWORD		TWaitEnd;							///< ウェイト時間（ms）
	char		*LangBuf;							///< スクリプトバッファ
	char		BusyFlg;							///< 動作状態フラグ
} EXEC_DATA;


extern	char		*EXEC_LangBuf; ///< 現在のスクリプトバッファ
extern	EXEC_DATA	*EXEC_LangInfo; ///< 現在のスクリプト情報
extern	char		NowLangFileName[64]; ///< 現在のスクリプトファイル名
extern	int			RunLangBlockNo; ///< 現在のスクリプトブロック番号
extern	int			PrevRunLangBlockNo; ///< 前のスクリプトブロック番号

/**
	スクリプトを読み込む.
	@param filename ファイル名
	@param [out] scr スクリプト情報
	@retval TRUE 成功
	@retval FALSE 失敗
*/
extern BOOL		EXEC_ReadLang( char *filename, EXEC_DATA *scr );

/**
	スクリプトの実行を開始.
	@param scr スクリプト情報
	@param scr_no スクリプトブロック番号
	@retval TRUE 成功
	@retval FALSE 失敗
*/
extern BOOL		EXEC_StartLang( EXEC_DATA *scr, int scr_no );

/**
	スクリプトデータを解放し、スクリプト情報を初期化する.
	@param scr スクリプト情報
*/
extern void		EXEC_ReleaseLang( EXEC_DATA *scr );

/**
	スクリプトの実行を終了.
	@param scr スクリプト情報
	@param init
*/
extern void		EXEC_EndLang( EXEC_DATA *scr, int init );

/**
	バイナリ列の先頭から 2 bytes を SHORT 値として取得.
	@param buf バイナリ列
	@return SHORT 値
*/
extern short	EXEC_GetShortValue( char *buf );

/**
	バイナリ列の先頭から 4 bytes を LONG 値として取得.
	@param buf バイナリ列
	@return LONG 値
*/
extern long		EXEC_GetLongValue( char *buf );

/**
	バイナリ列から値を取得
	@param buf バイナリ列
	@param mode 0 ならレジスタ値、そうでなければ LONG 値を取得
	@return (mode == 0) なら先頭 1 byte の CHAR 値を添字とするレジスタ値
	        そうでなければバイナリ列の先頭から 4 bytes を LONG 値として
*/
extern int		EXEC_GetValue( char *buf, int mode );

/**
	スクリプト処理全般.
	スクリプト処理時は毎フレーム呼び出されます。
	@param scr スクリプト情報
*/
extern int		EXEC_ControlLang( EXEC_DATA *scr );

/**
	スクリプトファイルを読み込み実行する.
	@param str ファイル名の拡張子より前の部分
	@retval 1 成功
	@retval 0 失敗
	@see EXEC_ReadLang()
	@see EXEC_StartLang()
*/
extern int		EXEC_SLoad( char *str );

/**
	スクリプトブロックをサブルーチンとしてコール.
	@param call_no スクリプトブロック番号
	@param next_pc 現在アドレスから次命令アドレスまでの差
	@param num レジスタ[0-14]に与える値の配列
*/
extern void EXEC_OprCallFunc( int call_no, int next_pc, long *num );


#define	EXEC_GetParam( N )		( EXEC_LangInfo->reg[ ( N ) ]         ) ///< レジスタ値を取得
#define	EXEC_SetParam( N, V )	( EXEC_LangInfo->reg[ ( N ) ] = ( V ) ) ///< レジスタに値を代入
#define	EXEC_AddPC( N )			( EXEC_LangInfo->pc += ( N )          ) ///< プログラムカウンタを進める
#define	EXEC_GetPC				( EXEC_LangInfo->pc                   ) ///< プログラムカウンタ取得
#define	EXEC_GetBusyFlag			( EXEC_LangInfo->BusyFlg              ) ///< 動作状態フラグを取得


#endif 
