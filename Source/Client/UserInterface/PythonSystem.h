/// 1.
// Search
	} TConfig;

// Add above
#if defined(ENABLE_FOV_OPTION)
		float fFOV;
#endif

/// 2.
// Search
	int GetDistance();

// Add below
#if defined(ENABLE_FOV_OPTION)
	// FoV
	float GetFOV();
	void SetFOV(float c_fValue);
#endif
