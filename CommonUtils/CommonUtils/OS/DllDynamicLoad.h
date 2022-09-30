#pragma once
#ifndef __DLL_DYNAMIC_LOAD_H__
#define __DLL_DYNAMIC_LOAD_H__

#include "../CommonDataDefine.h"

bool LoadDll(void* handle, const string& dll_name);

bool FreeDll(void* handle);

template<typename T>
bool GetDllFunc(T func, void* handle, const string& func_name);

bool IsValidIP(const string& ip);

bool GetLocalTime();


#endif // !__DLL_DYNAMIC_LOAD_H__
