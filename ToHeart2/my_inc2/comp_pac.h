/** @file
	PACK�t�@�C���֘A.
*/


#ifndef _PACMAIN_H_
#define _PACMAIN_H_




typedef struct {
	DWORD	type;		
	char	fname[24];	
	DWORD	offset;		
	DWORD	size;		
}FILE_INFO;

typedef struct {
	FILE_INFO	fi;
	int			pos;
}OPEN_FILE_INFO;

typedef struct {
	DWORD	head;		
	DWORD	famount;	
}PAC_FILE_INFO;


/**
	PACK�t�@�C���̒��Ƀt�@�C�������݂��邩���`�F�b�N���܂�.
	@param pname �`�F�b�N�̑ΏۂƂȂ�PACK�t�@�C���ւ̃p�X�B".pak"�Ƃ���
		�g���q�������ꂽ�t�@�C�����`�F�b�N����܂��B
	@param fname �`�F�b�N�̑ΏۂƂȂ�PACK�t�@�C�����̃t�@�C�����B
	@return pname�Ŏw�肵��PACK�t�@�C�����ɂ�����fname�Ŏw�肵���t�@�C����
		���������C���f�b�N�X�B������Ȃ������ꍇ��0���Ԃ���܂��B
		�Ԃ�l�̃C���f�b�N�X��1����n�܂�܂��B
	@see PAC_CheckPackFile()
*/
extern DWORD PAC_CheckFile( char *pname, char *fname );

/**
	PACK�t�@�C���̒��̃t�@�C���̓��e���o�b�t�@�[�փR�s�[���܂�.
	�t�@�C���̓��e���L���b�V������Ă���ꍇ�́A��������R�s�[����܂��B
	@param pname PACK�t�@�C���ւ̃p�X�B
	@param fname PACK�t�@�C�����̃t�@�C�����B
	@param buf �t�@�C���̓��e���R�s�[���邽�߂̃o�b�t�@�[�B
	@return �t�@�C���T�C�Y�B
	@see PAC_OpenPackFile()
*/
extern DWORD PAC_LoadFile( char *pname, char *fname, char **buf );

extern DWORD PAC_AllFilecheck( char *pname );

/**
	PACK�t�@�C���̒��Ƀt�@�C�������݂��邩���`�F�b�N���܂�.
	@param pname �`�F�b�N�̑ΏۂƂȂ�PACK�t�@�C���ւ̃p�X�B
	@param fname �`�F�b�N�̑ΏۂƂȂ�PACK�t�@�C�����̃t�@�C�����B
	@return pname�Ŏw�肵��PACK�t�@�C�����ɂ�����fname�Ŏw�肵���t�@�C����
		���������C���f�b�N�X�B������Ȃ������ꍇ��0���Ԃ���܂��B
		�Ԃ�l�̃C���f�b�N�X��1����n�܂�܂��B
	@see PAC_CheckFile()
*/
extern int PAC_CheckPackFile( char *pname, char *fname );

/**
	PACK�t�@�C���̒��̃t�@�C���̓��e���o�b�t�@�[�փR�s�[���܂�.
	�t�@�C���̓��e���L���b�V������Ă��邩�͊m�F���܂���B
	@param pname PACK�t�@�C���ւ̃p�X�B
	@param fname PACK�t�@�C�����̃t�@�C�����B
	@param buf �t�@�C���̓��e���R�s�[���邽�߂̃o�b�t�@�[�B
	@return �t�@�C���T�C�Y�B
	@see PAC_LoadFile()
*/
extern int PAC_OpenPackFile( char *pname, char *fname, char **buf );

extern OPEN_FILE_INFO PAC_OpenFileHandle( char *pname, char *fname, HANDLE *fh );
extern void PAC_OpenFileHandle( HANDLE *fh );
extern DWORD PAC_SeekFileHandle( HANDLE *fh, OPEN_FILE_INFO *fi, int pos );
extern DWORD PAC_ReedFileHandle( HANDLE *fh, OPEN_FILE_INFO *fi, BYTE *buf, int size );


#endif
