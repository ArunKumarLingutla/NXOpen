#include <uf.h>
#include <uf_ui.h>
#include "Header.hpp"

extern "C" DllExport void ufusr(char* parm, int* returnCode, int rlen) {
	UF_initialize();
	GetBodiesAndFaces();
	UF_terminate();
}
extern "C" DllExport int ufusr_ask_unload() {
	return UF_UNLOAD_IMMEDIATELY;
}

