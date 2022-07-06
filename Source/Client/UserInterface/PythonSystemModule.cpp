/// 1.
// Search
void initsystem()

// Add above
#if defined(ENABLE_FOV_OPTION)
PyObject* systemSetFOV(PyObject* poSelf, PyObject* poArgs)
{
	float fValue;
	if (!PyTuple_GetFloat(poArgs, 0, &fValue))
		return Py_BuildException();

	CPythonSystem::Instance().SetFOV(fValue);
	return Py_BuildNone();
}

PyObject* systemGetFOV(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("f", CPythonSystem::Instance().GetFOV());
}
#endif

/// 2.
// Search
		{ NULL, NULL, NULL }

// Add above
#if defined(ENABLE_FOV_OPTION)
		{ "SetFOV", systemSetFOV, METH_VARARGS },
		{ "GetFOV", systemGetFOV, METH_VARARGS },
#endif
