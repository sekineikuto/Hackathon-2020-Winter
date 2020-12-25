//*************************************************************************************************************
//
// �X�g�[���[���� [story.h]
// Author:NISHIYAMA KOKI
//
//*************************************************************************************************************
#ifndef _STORY_H_
#define _STORY_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "mode.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class C2DUi;
class CStory : public CMode
{
public:
	/* �񋓌^ */
	typedef enum
	{
		TYPE_STORY_1= 0,
		TYPE_STORY_2,
		TYPE_STORY_3,
		TYPE_MAX
	} TYPE;



	/* �X�g�[���[�ƃ`���[�g���A���ǂ����ł��g���邩�� */
	// �g�嗦���
	typedef struct SCALING
	{
		SCALING()
		{
			OriginSize = D3DXVECTOR2(0.0f, 0.0f);
			fScal = 1.0f;
			fScalChange = 0.0f;
			fScalDiff = 0.0f;
			nTimeChange = 0;
			nCntTimeChange = 0;
			bChange = false;
		}
		// �ݒ�
		void Set(
			D3DXVECTOR2 const & SouceSize,
			float const & fSouceScalChange,
			int const & nSouceTimeChange
		)
		{
			OriginSize = SouceSize;
			fScalChange = fSouceScalChange;
			nTimeChange = nSouceTimeChange;
			fScalDiff = (fScalChange - fScal) / nTimeChange;
		}
		D3DXVECTOR2 OriginSize;			// ���̃T�C�Y
		float fScal;					// �g�嗦
		float fScalChange;				// �ڕW�g�嗦
		float fScalDiff;				// �g�嗦�㏸��
		int nTimeChange;				// �؂�ւ�鎞��
		int nCntTimeChange;				// �؂�ւ�鎞�ԃJ�E���g
		bool bChange;					// �؂�ւ�蒆
	} SCALING, *P_SCALING;

	typedef struct PERFORM2DUI
	{
		SCALING * pScal;
		C2DUi * pC2dui;
	} PERFORM2DUI;
	// �T�C�Y�ύX�̍X�V����
	static void Update_SizeChange(PERFORM2DUI * pPerfomUi);
	// ���oUI�̏���������
	static void Init_PerfomUi(int const & nMaxUi, PERFORM2DUI * pPerfomUi);






	/* �֐� */
	CStory() {};						// �R���X�g���N�^
	~CStory() {};						// �f�X�g���N�^

	static CStory *Create(void);		// ����
	void Init(void);					// ������
	void Uninit(void);					// �I��
	void Update(void);					// �X�V
	void Draw(void);					// �`��

private:
	PERFORM2DUI m_apPerfomUi[TYPE::TYPE_MAX];	// �QDUI�|�C���^
	float m_fBgTexY;							// �w�i�e�N�X�`���[y
};

#endif