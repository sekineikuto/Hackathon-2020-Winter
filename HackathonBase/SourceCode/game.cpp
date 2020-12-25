//*************************************************************************************************************
//
// ゲーム処理 [game.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "game.h"
#include "texture.h"
#include "2DUI.h"
#include "player.h"
#include "keyboard.h"
#include "renderer.h"
#include "fade.h"
#include "enemyMana.h"

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define LINK_GAMEUIINFO	("DATA/TEXT/UIInfo/gameUIInfo.txt")		// UI情報のあるテキストファイル
#define TIME_DEFAULT	(60)									// 最初のタイム

//-------------------------------------------------------------------------------------------------------------
// 静的メンバ変数の初期化
//-------------------------------------------------------------------------------------------------------------
CONST D3DXVECTOR3 CGame::m_InitPosPlayer = D3DXVECTOR3(640.0f, 360.0f, 0.0f);
CONST D3DXVECTOR2 CGame::m_InitSizePlayer = D3DXVECTOR2(60.0f, 60.0f);
//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
CGame * CGame::Create(void)
{
	CGame *pGame = new CGame;
	pGame->Init();
	return pGame;
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
void CGame::Init(void)
{
	// ゲームUIの生成
	CreateGameUI();

	// 敵マネージャーの生成
	m_pEnemyMana = CEnemyMana::Create();
	m_mode = MODE_NONE;
	m_nCntMode = ML_INT_UNSET;

	m_pPlayer = CPlayer::Create(m_InitPosPlayer, m_InitSizePlayer);
}

//-------------------------------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------------------------------
void CGame::Uninit(void)
{
	if (m_pEnemyMana)
	{
		m_pEnemyMana->Uninit();
		delete m_pEnemyMana;
		m_pEnemyMana = nullptr;
	}
}

//-------------------------------------------------------------------------------------------------------------
// 更新
//-------------------------------------------------------------------------------------------------------------
void CGame::Update(void)
{
	// モードの遷移
	ModeTrans();
	// マネージャーの更新
	m_pEnemyMana->Update();
}

//-------------------------------------------------------------------------------------------------------------
// 描画
//-------------------------------------------------------------------------------------------------------------
void CGame::Draw(void)
{
	// マネージャーの描画
	m_pEnemyMana->Draw();
}

//-------------------------------------------------------------------------------------------------------------
// ゲームUIの生成
//-------------------------------------------------------------------------------------------------------------
void CGame::CreateGameUI(void)
{
	N2Dui_seting seting;
	seting.bDisp = true;
	seting.col = ML_D3DXCOR_SET;
	seting.fRotation = ML_FLOAT_UNSET;

	// ペア数
	seting.nTextureID = CTexture::NAME_NUMBER;
	seting.pos = D3DXVECTOR3(640.0f, 360.0f, 0.0f);
	seting.size = D3DXVECTOR2(200.0f, 200.0f);
	m_pGameUI[GAMEUI_PAIR] = C2DUi::Create(seting, CScene::PRIORITY_BUI);

	// スコア
	seting.mask.unMask = N2Dui_mask::E_M_NUMBER;
	seting.nTextureID = CTexture::NAME_NUMBER;
	seting.nValue = 0;
	seting.pos = D3DXVECTOR3(640.0f, 360.0f, 0.0f);
	seting.size = D3DXVECTOR2(200.0f, 200.0f);
	m_pGameUI[GAMEUI_SCORE] = C2DUi::Create(seting, CScene::PRIORITY_BUI);

	// タイマー
	seting.mask.unMask = N2Dui_mask::E_M_NUMBER;
	seting.nTextureID = CTexture::NAME_NUMBER;
	seting.nValue = TIME_DEFAULT;
	seting.pos = D3DXVECTOR3(640.0f, 360.0f, 0.0f);
	seting.size = D3DXVECTOR2(200.0f, 200.0f);
	m_pGameUI[GAMEUI_TIMER] = C2DUi::Create(seting, CScene::PRIORITY_BUI);
}

//-------------------------------------------------------------------------------------------------------------
// モード遷移
//-------------------------------------------------------------------------------------------------------------
void CGame::ModeTrans(void)
{
	if (CManager::GetKeyboard().GetTrigger(DIK_RETURN))
	{
		if (CManager::GetRenderer().GetFade()->GetFadeState() == CFade::FADE_NONE)
		{
			CManager::GetRenderer().GetFade()->SetFade(CManager::MODE_TITLE);
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
// モードの設定
//-------------------------------------------------------------------------------------------------------------
void CGame::SetMode(MODE mode)
{
	if (m_mode != mode)
	{
		m_mode = mode;
		m_nCntMode = ML_INT_UNSET;
	}
}
