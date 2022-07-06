/// 1.
// Search @ void CPythonApplication::RenderGame
		m_pyGraphic.SetPerspective(30.0f, fAspect, 100.0, fFarClip);

// Add below
#if defined(ENABLE_FOV_OPTION)
		m_pyGraphic.SetPerspective(CPythonSystem::instance().GetFOV(), fAspect, 100.0, fFarClip);
#else
		m_pyGraphic.SetPerspective(30.0f, fAspect, 100.0, fFarClip);
#endif

/// 2.
// Search @ void CPythonApplication::RenderGame
	m_pyGraphic.SetPerspective(30.0f, fAspect, 100.0, fFarClip);

// Replace with
#if defined(ENABLE_FOV_OPTION)
	m_pyGraphic.SetPerspective(CPythonSystem::instance().GetFOV(), fAspect, 100.0, fFarClip);
#else
	m_pyGraphic.SetPerspective(30.0f, fAspect, 100.0, fFarClip);
#endif

/// 3.
// Search @ void CPythonApplication::UpdateGame
		s.SetPerspective(30.0f, fAspect, 100.0f, fFarClip);

// Replace with
#if defined(ENABLE_FOV_OPTION)
		s.SetPerspective(CPythonSystem::instance().GetFOV(), fAspect, 100.0f, fFarClip);
#else
		s.SetPerspective(30.0f, fAspect, 100.0f, fFarClip);
#endif
