/// 1.
// Search
void CScreen::SetColorOperation()

// Add above
#if defined(ENABLE_FOV_OPTION)
void CScreen::RenderTriangle3d(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy, float cz)
{
	assert(ms_lpd3dDevice != NULL);

	SPDTVertexRaw vertices[3] =
	{
		{ ax, ay, az, ms_diffuseColor, 0.0f, 0.0f },
		{ bx, by, bz, ms_diffuseColor, 0.0f, 0.0f },
		{ cx, cy, cz, ms_diffuseColor, 0.0f, 0.0f },
	};

	if (SetPDTStream(vertices, 3))
	{
		STATEMANAGER.SetTexture(0, NULL);
		STATEMANAGER.SetTexture(1, NULL);
		STATEMANAGER.SetVertexShader(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
		STATEMANAGER.DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
	}
}

void CScreen::RenderMiniMapFilter(float fx, float fy, float fz, float fRadius, int iStep, float fAngle, float fRotation, const D3DXVECTOR3& rCenterOffset)
{
	std::vector<D3DXVECTOR3> pts;
	pts.reserve(iStep + 1);

	float fDelta = D3DX_PI / 180.0f * fAngle / iStep;
	for (float fTheta = (fRotation - fAngle / 2.0f) * D3DX_PI / 180.0f; fTheta < (fRotation + fAngle / 2.0f) * D3DX_PI / 180.0f; fTheta += fDelta)
	{
		pts.push_back(D3DXVECTOR3(fx + fRadius * cosf(fTheta),
			fy + fRadius * sinf(fTheta),
			fz));
	}

	for (int i = 0; i < pts.size() - 1; ++i)
	{
		RenderTriangle3d(pts[i].x, pts[i].y, pts[i].z, fx + rCenterOffset.x, fy + rCenterOffset.y, fz + rCenterOffset.z, pts[i + 1].x, pts[i + 1].y, pts[i + 1].z);
	}
}
#endif
