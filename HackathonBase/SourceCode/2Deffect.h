// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// 2Dエフェクトの処理[2Deffect.h]
// Author : Nishiyama koki
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef _2DEFFECT_H_
#define _2DEFFECT_H_

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// インクルードファイル
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "effect.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// マクロ定義
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 前方宣言
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// クラス定義
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class C2DEffect :public CEffect
{
public:
	/* 関数 */
	// コンストラクタ
	C2DEffect();
	// デストラクタ
	~C2DEffect();
	// 全リソース情報の読み込み処理
	static HRESULT Load(void);
	// 全リソース情報の開放
	static void Unload(void);
	// 初期化処理
	void Init(void);
	// 終了処理
	void Uninit(void);
	// 更新処理
	void Update(void);
	// 描画処理
	void Draw(void);
	// 生成処理
	static C2DEffect *Create(void);
#ifdef _DEBUG
	// デバッグ処理
	void Debug(void);
#endif // _DEBUG
	// 頂点作成
	//	pDevice	: デバイス情報
	HRESULT MakeVertex(
		LPDIRECT3DDEVICE9 pDevice	// デバイス情報
	);
	// 全体の設定
	//	EffectType	: エフェクトタイプ
	//	nTexType	: テクスチャータイプ
	//	pos			: 位置
	//	rot			: 回転
	//	move		: 移動量
	//	col			: 色
	//	size		: サイズ
	//	nLife		: ライフ
	//	Blend		: ブレンドタイプ
	//	sizeValue	: サイズ変化
	static void Set2DEffect(
		EFFECT_TYPE const &EffectType,										// エフェクトタイプ
		int const &nTexType,												// テクスチャータイプ
		D3DXVECTOR3 const &pos,												// 位置
		D3DXVECTOR3 const &rot,												// 回転
		D3DXVECTOR3 const &move,											// 移動量
		D3DXCOLOR const &col,												// 色
		D3DXVECTOR2 const &size,											// サイズ
		int const &nLife,													// ライフ
		ANIMATION_LOAD const & Anim,										// アニメーション情報読み込み
		CRenderer::BLEND const &Blend = CRenderer::BLEND_ADD_TRANSLUCENT,	// ブレンドタイプ
		D3DXVECTOR2 const &sizeValue = D3DXVECTOR2(0.0f,0.0f),				// サイズ変化値
		float const &fAlphaValue = 0.0f										// α変化値
	);
private:
	/* 関数 */
	// 頂点サイズ設定
	//	pVtx	: 2D頂点情報
	//	pEffect	: エフェクト情報
	//	nIndex	: 番号情報
	static void SetVartexSize(
		CRenderer::VERTEX_2D *pVtx,	// 2D頂点情報
		EFFECT *pEffect = NULL,		// エフェクト情報
		const int *nIndex = NULL	// 番号情報
	);
	// 頂点カラー設定
	//	pVtx	: 2D頂点情報
	//	pEffect	: エフェクト情報
	//	nIndex	: 番号情報
	static void SetVetexColor(
		CRenderer::VERTEX_2D *pVtx,	// 2D頂点情報
		EFFECT *pEffect = NULL,		// エフェクト情報
		const int *nIndex = NULL	// 番号情報
	);
	// 頂点テクスチャー設定
	//	pVtx	: 2D頂点情報
	//	pEffect	: エフェクト情報
	//	nIndex	: 番号情報
	static void SetVetexTex(
		CRenderer::VERTEX_2D *pVtx,	// 2D頂点情報
		EFFECT *pEffect = NULL,		// エフェクト情報
		const int *nIndex = NULL	// 番号情報
	);
	// 位置上限処理
	//	pEffect	: エフェクト情報
	static void Pos_Limit(
		EFFECT *pEffect = NULL		// エフェクト情報
		);
	/* 変数 */
	static LPDIRECT3DVERTEXBUFFER9	m_pVtxBuff;					// バッファ情報
	static EFFECT					m_aEffect[EFFECT_MAX];		// エフェクト情報
};

#endif