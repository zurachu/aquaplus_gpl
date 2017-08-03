/** @file
	PACKファイル関連.
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
	PACKファイルの中にファイルが存在するかをチェックします.
	@param pname チェックの対象となるPACKファイルへのパス。".pak"という
		拡張子が足されたファイルがチェックされます。
	@param fname チェックの対象となるPACKファイル内のファイル名。
	@return pnameで指定したPACKファイル内におけるfnameで指定したファイルが
		見つかったインデックス。見つからなかった場合は0が返されます。
		返り値のインデックスは1から始まります。
	@see PAC_CheckPackFile()
*/
extern DWORD PAC_CheckFile( char *pname, char *fname );

/**
	PACKファイルの中のファイルの内容をバッファーへコピーします.
	ファイルの内容がキャッシュされている場合は、そこからコピーされます。
	@param pname PACKファイルへのパス。
	@param fname PACKファイル内のファイル名。
	@param buf ファイルの内容をコピーするためのバッファー。
	@return ファイルサイズ。
	@see PAC_OpenPackFile()
*/
extern DWORD PAC_LoadFile( char *pname, char *fname, char **buf );

extern DWORD PAC_AllFilecheck( char *pname );

/**
	PACKファイルの中にファイルが存在するかをチェックします.
	@param pname チェックの対象となるPACKファイルへのパス。
	@param fname チェックの対象となるPACKファイル内のファイル名。
	@return pnameで指定したPACKファイル内におけるfnameで指定したファイルが
		見つかったインデックス。見つからなかった場合は0が返されます。
		返り値のインデックスは1から始まります。
	@see PAC_CheckFile()
*/
extern int PAC_CheckPackFile( char *pname, char *fname );

/**
	PACKファイルの中のファイルの内容をバッファーへコピーします.
	ファイルの内容がキャッシュされているかは確認しません。
	@param pname PACKファイルへのパス。
	@param fname PACKファイル内のファイル名。
	@param buf ファイルの内容をコピーするためのバッファー。
	@return ファイルサイズ。
	@see PAC_LoadFile()
*/
extern int PAC_OpenPackFile( char *pname, char *fname, char **buf );

extern OPEN_FILE_INFO PAC_OpenFileHandle( char *pname, char *fname, HANDLE *fh );
extern void PAC_OpenFileHandle( HANDLE *fh );
extern DWORD PAC_SeekFileHandle( HANDLE *fh, OPEN_FILE_INFO *fi, int pos );
extern DWORD PAC_ReedFileHandle( HANDLE *fh, OPEN_FILE_INFO *fi, BYTE *buf, int size );


#endif
