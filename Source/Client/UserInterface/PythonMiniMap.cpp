/// 1.
// Add
#if defined(ENABLE_FOV_OPTION)
#	include "PythonApplication.h"
#endif

/// 2.
// Search @ void CPythonMiniMap::Render
		m_MiniMapCameraraphicImageInstance.SetRotation(pkCmrCur->GetRoll());
		m_MiniMapCameraraphicImageInstance.Render();

// Replace with
#if defined(ENABLE_FOV_OPTION)
		// NOTE : Generic MiniMap camera texture rendering block with FoV. - [Distraught]

		const float fFOV = CPythonSystem::instance().GetFOV();

		const float fAlpha = 0.3f; // how dark you want unseen areas to be
		const float fRadius = 128.0f / 2.0f; // your minimap size / 2.0f
		const float fOffset = 10.0f; // offset for putting the edge of the triangle behind the character

		const float fDir = pkCmrCur->GetRoll() - 270.0f;
		const float fX = (m_fScreenX + m_fWidth / 2.0f);
		const float fY = (m_fScreenY + m_fHeight / 2.0f);

		STATEMANAGER.SaveRenderState(D3DRS_TEXTUREFACTOR, D3DXCOLOR(1.0f, 1.0f, 1.0f, fAlpha));
		STATEMANAGER.SaveTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		STATEMANAGER.SaveTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TFACTOR);
		STATEMANAGER.SaveTextureStageState(0, D3DTSS_COLOROP, D3DTOP_ADD);

		CScreen screen;
		screen.SetDiffuseColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, fAlpha));
		screen.RenderMiniMapFilter(fX, fY, 0,
			fRadius,
			(360.0f - fFOV) / 4.0f,
			360.0f - fFOV,
			fDir,
			D3DXVECTOR3(cosf(D3DX_PI / 180.0f * fDir) * fOffset, sinf(D3DX_PI / 180.0f * fDir) * fOffset, 0.0f));

		STATEMANAGER.RestoreTextureStageState(0, D3DTSS_COLORARG1);
		STATEMANAGER.RestoreTextureStageState(0, D3DTSS_COLORARG2);
		STATEMANAGER.RestoreTextureStageState(0, D3DTSS_COLOROP);
		STATEMANAGER.RestoreRenderState(D3DRS_TEXTUREFACTOR);
#else
		m_MiniMapCameraraphicImageInstance.SetRotation(pkCmrCur->GetRoll());
		m_MiniMapCameraraphicImageInstance.Render();
#endif
