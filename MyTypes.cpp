
#include "MyTypes.h"

#pragma warning(disable:4996)

#if Use_MATLAB == 1
std::unique_ptr<MATLABEngine> MATLABEngineClass::_matlabptr = NULL;

CRITICAL_SECTION* MATLABEngineClass::_CS = NULL;
bool MATLABEngineClass::_inited = false;

#endif




