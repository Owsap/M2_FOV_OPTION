/// 1.
// Search

// Add below
#if defined(ENABLE_FOV_OPTION)
	PyModule_AddIntConstant(poModule, "ENABLE_FOV_OPTION", 1);
	PyModule_AddIntConstant(poModule, "DEFAULT_CAMERA_PERSPECTIVE", c_fDefaultCameraPerspective);
	PyModule_AddIntConstant(poModule, "MIN_CAMERA_PERSPECTIVE", c_fMinCameraPerspective);
	PyModule_AddIntConstant(poModule, "MAX_CAMERA_PERSPECTIVE", c_fMaxCameraPerspective);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_FOV_OPTION", 0);
#endif
