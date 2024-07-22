/* API for s-functions and Stateflow to support Simulink String */

/* Copyright 2015-2021 The MathWorks, Inc. */

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#ifndef _sl_string_sfcn_api_h_
#define _sl_string_sfcn_api_h_

#include "simulink_spec.h"

/* =================== String data type APIs ==================== */
/* Return default buffer size (Bytes) for dynamic (unbounded) string data type. */
SIMULINK_EXPORT_EXTERN_C size_t ssGetDynamicStringDefaultBufferSize(SimStruct* S);

/* Return buffer size (Bytes) for a string data type - N+1 for 'stringtype(N)' or model config
 * setting for 'string'. */
SIMULINK_EXPORT_EXTERN_C size_t ssGetStringDataTypeBufferSize(SimStruct* S, int dataType);

/* Return diagnostic setting in model config set for string truncation - Error/Warning/None. */
SIMULINK_EXPORT_EXTERN_C BDErrorValue ssGetStringTruncationDiagnosticSetting(SimStruct* S);
SIMULINK_EXPORT_EXTERN_C int ssGetTargetLangStandard(SimStruct* S);

/* =================== String data type support opt-in ====================== */
/* The opt-in APIs needd to be called after EvalDlgPrms() stage, otherwise they won't have effect.
 */
SIMULINK_EXPORT_EXTERN_C void ssSetInputSupportStringDataType(SimStruct* S,
                                                              int portIdx,
                                                              bool support);
SIMULINK_EXPORT_EXTERN_C void ssSetOutputSupportStringDataType(SimStruct* S,
                                                               int portIdx,
                                                               bool support);
/* =============================================================== */

/* =================== C++ String data type interface package checking ====================== */
/*Needed to pass the information that "we should use cpp string class" to stateflow string*/
SIMULINK_EXPORT_EXTERN_C bool ssGetUseCppClass(SimStruct* S);
/* =============================================================== */
#endif /* _sl_string_sfcn_api_h_ */
