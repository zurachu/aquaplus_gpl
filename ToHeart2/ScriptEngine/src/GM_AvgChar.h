/** @file
	AVG 立ち絵関連の定義.
*/

#ifndef	_GM_AVGCHAR_H_
#define _GM_AVGCHAR_H_


extern void SetCharPosShake( int shx, int shy, int disp );
extern void SetCharBright( int r, int g, int b );

extern void SetCharHalfTone( int flag );


/**
	立ち絵の表示位置を取得.
	@param char_no キャラ
	@return 表示位置
*/
extern int AVG_CheckCharLocate( int char_no );

/**
	立ち絵を表示登録.
	@param char_no キャラ
	@param pose ポーズ
	@param locate 位置
	@param layer レイヤ
	@param in_type 表示方法
	@param bright 明度
	@param alph α値
	@param frame 表示までのフレーム数
*/
extern void AVG_SetChar( int char_no, int pose, int locate, int layer, int in_type, int bright, int alph, int frame );

/**
	立ち絵リソースを解放.
	@param char_index 立ち絵情報配列の添字
*/
extern void AVG_ReleaseChar( int char_index );

/**
	立ち絵を表示解除.
	@param char_no キャラ
	@param out_type 消去方法
	@param frame 消去までのフレーム数
*/
extern void AVG_ResetChar( int char_no, int out_type, int frame );

extern void AVG_OpenChar( void );
extern void AVG_CloseChar( void );

/**
	立ち絵のポーズ変更.
	@param char_no キャラ
	@param pose ポーズ
	@param in_type 変更方法
	@param frame 変更までのフレーム数
*/
extern void AVG_SetCharPose( int char_no, int pose, int in_type, int frame );

/**
	立ち絵の表示位置変更.
	@param char_no キャラ
	@param locate 位置
	@param frame 変更までのフレーム数
*/
extern void AVG_SetCharLocate( int char_no, int locate, int frame );

/**
	立ち絵の描画レイヤ変更.
	@param char_no キャラ
	@param layer レイヤ
*/
extern void AVG_SetCharLayer( int char_no, int layer );

/**
	立ち絵のフェード変更.
	@param char_no キャラ
	@param fade 明度
	@param fade_count 変更までのフレーム数
*/
extern void AVG_SetCharBright( int char_no, int fade, int fade_count );

/**
	立ち絵のαブレンド変更.
	@param char_no キャラ
	@param alph α値
	@param fade_count 変更までのフレーム数
*/
extern void AVG_SetCharAlph( int char_no, int alph, int fade_count );

/**
	解放待ちの全立ち絵リソースを解放.
*/
extern void AVG_SetBackReleaseChar( void );

extern void AVG_SetBackChar( int x, int y, int char_disp );
extern BOOL AVG_WaitChar( int char_no );

/**
	立ち絵操作全般.
	メイン画面中は毎フレーム呼び出されます
*/
extern void AVG_ControlChar( void );

extern void AVG_ControlSpChar( void );


extern BOOL AVG_ConfigCheckChar(void);
extern void AVG_SetSaveDataChar( AVG_SAVE_DATA	*sdata );
extern void AVG_InitChar(void);


#endif//_GM_AVGCHAR_H_