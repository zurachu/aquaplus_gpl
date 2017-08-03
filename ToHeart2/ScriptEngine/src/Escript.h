/** @file
	�C�x���g�X�N���v�g�֘A�̒�`.
*/

#ifndef _ESCRIPT_H__
#define _ESCRIPT_H__

#define	ESC_OBJSADDR			0x80028000							
#define	ESC_OBJDSIZEMAX			0x100000							
#define ESC_FLAG_MAX			1024								

// �t���O�ԍ�
#define	_MONTH		0	///< ��
#define	_DAY		1	///< ��
#define	_TIME		2	///< ����
#define	_EVENT_NEXT	3	///< ���̃C�x���g
#define	_EVENT_END	4	///< �C�x���g�I��
#define	_DEFAULT_NAME	5	///< ���O�f�t�H���g
#define	_CALENDER_SKIP	6	
#define	_CLOCK_TIME		7	///< ���v

#define	_DEBUG_CALL		9	

#define ESC_SetFlag( N, D )		ESC_FlagBuf[ ( N ) ] = ( D )		///< �t���O�ɒl����
#define ESC_GetFlag( N )		ESC_FlagBuf[ ( N ) ]				///< �t���O�l���擾

/**
	���߂ɕK�v�ȃp�����[�^��ǂݍ��݁A���߂����s.
	@param opr ���߃R�[�h
*/
extern int  ESC_OprControl( int opr );

/**
	�t���O��������.
*/
extern void ESC_InitFlag( void );


extern void ESC_InitEOprFlag( void );


extern int	ESC_FlagBuf[ ESC_FLAG_MAX ]; ///< �Q�[���ʃZ�[�u�t���O
extern int	ESC_GameFlagBuf[ ESC_FLAG_MAX ]; ///< �Q�[���S�̃t���O

extern void SetVoiceDialog( int flag );
extern void AddVoiceDialogMes( char *mes, ...);

extern void ESC_SetDrawFlag( void );
extern void ESC_CodeCheck(void);


#define	SCRIPT_BLOCK_MAX		256 ///< �X�N���v�g�u���b�N����


/// �X�N���v�g�w�b�_
typedef struct {
	short			h1, h2;
	long			Fsize; ///< �t�@�C���T�C�Y
	unsigned long	BlockAddres[ SCRIPT_BLOCK_MAX ]; ///< �X�N���v�g�u���b�N�̃A�h���X
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
	�X�N���v�g�f�[�^�p�b�P�[�W�̂���f�B���N�g�����w��
	@param pac_dir �f�B���N�g����
*/
extern void EXEC_SetPackDir( char *pac_dir );

#define	MAIN_SCRIPT				0

#define SCCODE_NOOPR			0					///< ���߂Ȃ�
#define SCCODE_RUN				1					///< ���s��
#define SCCODE_WAIT_WAIT		2					///< �t���[�����P�ʂ̃E�F�C�g��
#define SCCODE_WAIT_TWAIT		3					///< �~���b�P�ʂ̃E�F�C�g��
#define SCCODE_WAIT_SLOAD		4					///< �X�N���v�g�ǂݍ��ݒ�
#define SCCODE_WAIT_DEBUG		0xFF				

#define REGISTER_MAX			50					///< ���W�X�^����
#define	STACK_MAX				512					///< �X�^�b�N����
#define	TASK_MAX				8					///< �^�X�N�����i�s�g�p�j
enum{												
	SCRMODE_EVENT,
	SCRMODE_MAX
};

// EXEC_OprCalc() �ŗp����f�[�^�v�f���e�񋓒l
enum {
	FACT_VAL = 0, ///< �l
	FACT_REG, ///< ���W�X�^�ԍ�
	FACT_CLC, ///< ���Z�q
	FACT_END, ///< �I��
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


/// �X�N���v�g�f�[�^���\����
typedef struct {									
	DWORD		BlockAddres[SCRIPT_BLOCK_MAX];		///< �X�N���v�g�u���b�N�̃A�h���X
	long		sp_buf[STACK_MAX];					///< �X�^�b�N
	long		reg[REGISTER_MAX];					///< ���W�X�^
	DWORD		pc;									///< �v���O�����J�E���^
	DWORD		sp;									///< �X�^�b�N�|�C���^
	DWORD		WaitCounter;						///< �E�F�C�g�t���[�����v���J�E���^
	DWORD		WaitEnd;							///< �E�F�C�g�t���[����
	DWORD		TWaitEnd;							///< �E�F�C�g���ԁims�j
	char		*LangBuf;							///< �X�N���v�g�o�b�t�@
	char		BusyFlg;							///< �����ԃt���O
} EXEC_DATA;


extern	char		*EXEC_LangBuf; ///< ���݂̃X�N���v�g�o�b�t�@
extern	EXEC_DATA	*EXEC_LangInfo; ///< ���݂̃X�N���v�g���
extern	char		NowLangFileName[64]; ///< ���݂̃X�N���v�g�t�@�C����
extern	int			RunLangBlockNo; ///< ���݂̃X�N���v�g�u���b�N�ԍ�
extern	int			PrevRunLangBlockNo; ///< �O�̃X�N���v�g�u���b�N�ԍ�

/**
	�X�N���v�g��ǂݍ���.
	@param filename �t�@�C����
	@param [out] scr �X�N���v�g���
	@retval TRUE ����
	@retval FALSE ���s
*/
extern BOOL		EXEC_ReadLang( char *filename, EXEC_DATA *scr );

/**
	�X�N���v�g�̎��s���J�n.
	@param scr �X�N���v�g���
	@param scr_no �X�N���v�g�u���b�N�ԍ�
	@retval TRUE ����
	@retval FALSE ���s
*/
extern BOOL		EXEC_StartLang( EXEC_DATA *scr, int scr_no );

/**
	�X�N���v�g�f�[�^��������A�X�N���v�g��������������.
	@param scr �X�N���v�g���
*/
extern void		EXEC_ReleaseLang( EXEC_DATA *scr );

/**
	�X�N���v�g�̎��s���I��.
	@param scr �X�N���v�g���
	@param init
*/
extern void		EXEC_EndLang( EXEC_DATA *scr, int init );

/**
	�o�C�i����̐擪���� 2 bytes �� SHORT �l�Ƃ��Ď擾.
	@param buf �o�C�i����
	@return SHORT �l
*/
extern short	EXEC_GetShortValue( char *buf );

/**
	�o�C�i����̐擪���� 4 bytes �� LONG �l�Ƃ��Ď擾.
	@param buf �o�C�i����
	@return LONG �l
*/
extern long		EXEC_GetLongValue( char *buf );

/**
	�o�C�i���񂩂�l���擾
	@param buf �o�C�i����
	@param mode 0 �Ȃ烌�W�X�^�l�A�����łȂ���� LONG �l���擾
	@return (mode == 0) �Ȃ�擪 1 byte �� CHAR �l��Y���Ƃ��郌�W�X�^�l
	        �����łȂ���΃o�C�i����̐擪���� 4 bytes �� LONG �l�Ƃ���
*/
extern int		EXEC_GetValue( char *buf, int mode );

/**
	�X�N���v�g�����S��.
	�X�N���v�g�������͖��t���[���Ăяo����܂��B
	@param scr �X�N���v�g���
*/
extern int		EXEC_ControlLang( EXEC_DATA *scr );

/**
	�X�N���v�g�t�@�C����ǂݍ��ݎ��s����.
	@param str �t�@�C�����̊g���q���O�̕���
	@retval 1 ����
	@retval 0 ���s
	@see EXEC_ReadLang()
	@see EXEC_StartLang()
*/
extern int		EXEC_SLoad( char *str );

/**
	�X�N���v�g�u���b�N���T�u���[�`���Ƃ��ăR�[��.
	@param call_no �X�N���v�g�u���b�N�ԍ�
	@param next_pc ���݃A�h���X���玟���߃A�h���X�܂ł̍�
	@param num ���W�X�^[0-14]�ɗ^����l�̔z��
*/
extern void EXEC_OprCallFunc( int call_no, int next_pc, long *num );


#define	EXEC_GetParam( N )		( EXEC_LangInfo->reg[ ( N ) ]         ) ///< ���W�X�^�l���擾
#define	EXEC_SetParam( N, V )	( EXEC_LangInfo->reg[ ( N ) ] = ( V ) ) ///< ���W�X�^�ɒl����
#define	EXEC_AddPC( N )			( EXEC_LangInfo->pc += ( N )          ) ///< �v���O�����J�E���^��i�߂�
#define	EXEC_GetPC				( EXEC_LangInfo->pc                   ) ///< �v���O�����J�E���^�擾
#define	EXEC_GetBusyFlag			( EXEC_LangInfo->BusyFlg              ) ///< �����ԃt���O���擾


#endif 
