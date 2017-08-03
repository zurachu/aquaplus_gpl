/** @file
	AVG �����G�֘A�̒�`.
*/

#ifndef	_GM_AVGCHAR_H_
#define _GM_AVGCHAR_H_


extern void SetCharPosShake( int shx, int shy, int disp );
extern void SetCharBright( int r, int g, int b );

extern void SetCharHalfTone( int flag );


/**
	�����G�̕\���ʒu���擾.
	@param char_no �L����
	@return �\���ʒu
*/
extern int AVG_CheckCharLocate( int char_no );

/**
	�����G��\���o�^.
	@param char_no �L����
	@param pose �|�[�Y
	@param locate �ʒu
	@param layer ���C��
	@param in_type �\�����@
	@param bright ���x
	@param alph ���l
	@param frame �\���܂ł̃t���[����
*/
extern void AVG_SetChar( int char_no, int pose, int locate, int layer, int in_type, int bright, int alph, int frame );

/**
	�����G���\�[�X�����.
	@param char_index �����G���z��̓Y��
*/
extern void AVG_ReleaseChar( int char_index );

/**
	�����G��\������.
	@param char_no �L����
	@param out_type �������@
	@param frame �����܂ł̃t���[����
*/
extern void AVG_ResetChar( int char_no, int out_type, int frame );

extern void AVG_OpenChar( void );
extern void AVG_CloseChar( void );

/**
	�����G�̃|�[�Y�ύX.
	@param char_no �L����
	@param pose �|�[�Y
	@param in_type �ύX���@
	@param frame �ύX�܂ł̃t���[����
*/
extern void AVG_SetCharPose( int char_no, int pose, int in_type, int frame );

/**
	�����G�̕\���ʒu�ύX.
	@param char_no �L����
	@param locate �ʒu
	@param frame �ύX�܂ł̃t���[����
*/
extern void AVG_SetCharLocate( int char_no, int locate, int frame );

/**
	�����G�̕`�惌�C���ύX.
	@param char_no �L����
	@param layer ���C��
*/
extern void AVG_SetCharLayer( int char_no, int layer );

/**
	�����G�̃t�F�[�h�ύX.
	@param char_no �L����
	@param fade ���x
	@param fade_count �ύX�܂ł̃t���[����
*/
extern void AVG_SetCharBright( int char_no, int fade, int fade_count );

/**
	�����G�̃��u�����h�ύX.
	@param char_no �L����
	@param alph ���l
	@param fade_count �ύX�܂ł̃t���[����
*/
extern void AVG_SetCharAlph( int char_no, int alph, int fade_count );

/**
	����҂��̑S�����G���\�[�X�����.
*/
extern void AVG_SetBackReleaseChar( void );

extern void AVG_SetBackChar( int x, int y, int char_disp );
extern BOOL AVG_WaitChar( int char_no );

/**
	�����G����S��.
	���C����ʒ��͖��t���[���Ăяo����܂�
*/
extern void AVG_ControlChar( void );

extern void AVG_ControlSpChar( void );


extern BOOL AVG_ConfigCheckChar(void);
extern void AVG_SetSaveDataChar( AVG_SAVE_DATA	*sdata );
extern void AVG_InitChar(void);


#endif//_GM_AVGCHAR_H_