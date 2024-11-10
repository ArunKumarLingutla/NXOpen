#include <uf.h>
#include <uf_ui.h>
#include "NXOpenHeaders.hpp"

extern "C" DllExport void ufusr(char* parm, int* returnCode, int rlen) {
	try
	{
		UF_initialize();
		//GetBodies();
		//GetFaces();
		CreateLine();
		//CreatingNewPointFromMidPointOfline();
		CreatingLinePerpendicularToLine();
		UF_terminate();
	}
	catch (const std::exception&)
	{
		*returnCode = 1; // Failure
	}
}
extern "C" DllExport int ufusr_ask_unload() {
	return UF_UNLOAD_IMMEDIATELY;
}

