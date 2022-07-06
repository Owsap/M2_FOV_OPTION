/// 1.
// Search
	void SetColorOperation();

// Add above
#if defined(ENABLE_FOV_OPTION)
	void RenderTriangle3d(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy, float cz);
	void RenderMiniMapFilter(float fx, float fy, float fz, float fRadius, int iStep = 50, float fAngle = 360.0f, float fRotation = 0.0f, const D3DXVECTOR3& rCenterOffset = D3DXVECTOR3(0.0f, 0.0f, 0.0f));
#endif
