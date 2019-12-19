#pragma once

// #ifdef MY_DLL_EXPORTS
// #   define MY_DLL_EXP __declspec(dllexport)
// #else
// #   define MY_DLL_EXP __declspec(dllimport)
// #endif
#ifdef __cplusplus
extern "C" {
#endif



class WHYCAN_T {
public:
	void hello();
};



#ifdef __cplusplus
}
#endif
//#pragma once
//
//#ifdef MY_DLL_EXPORTS
//#   define MY_DLL_EXP __declspec(dllexport)
//#else
//#   define MY_DLL_EXP __declspec(dllimport)
//#endif
//
//class MY_DLL_EXP HelloDll {
//public:
//	void hello();
//};

