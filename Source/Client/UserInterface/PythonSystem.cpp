/// 1.
// Search @ void CPythonSystem::SetDefaultConfig
	m_Config.iShadowLevel = 3;

// Add below
#if defined(ENABLE_FOV_OPTION)
	m_Config.fFOV = c_fDefaultCameraPerspective;
#endif

/// 2.
// Search
bool CPythonSystem::IsUseDefaultIME()

// Add above
#if defined(ENABLE_FOV_OPTION)
float CPythonSystem::GetFOV()
{
	return m_Config.fFOV;
}

void CPythonSystem::SetFOV(float fFlag)
{
	m_Config.fFOV = fMINMAX(c_fMinCameraPerspective, fFlag, c_fMaxCameraPerspective);
}
#endif

/// 3.
// Search @ bool CPythonSystem::LoadConfig
		else if (!stricmp(command, "SOFTWARE_TILING"))
			m_Config.bSoftwareTiling = atoi(value);

// Add below
#if defined(ENABLE_FOV_OPTION)
		else if (!stricmp(command, "FOV"))
		{
			m_Config.fFOV = atof(value);
		}
#endif

/// 4.
// Search @ bool CPythonSystem::SaveConfig
	fprintf(fp, "\n");

// Add above
#if defined(ENABLE_FOV_OPTION)
	fprintf(fp, "FOV						%.2f\n", m_Config.fFOV);
#endif
