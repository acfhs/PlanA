#include "DllDynamicLoad.h"

#include "../CommonFunc.h"


bool LoadDll(void* handle, const string& dll_name)
{
#ifdef _WIN64
	wstring wstr_dll_name;
	if (!StringTWString(wstr_dll_name, dll_name))
	{
		return false;
	}
	handle = ::LoadLibrary(wstr_dll_name.c_str());
	
#elif __linux__
	handle = dlopen(dll_name.c_str());

#elif __APPLE__
#error "Not Support OS"
#else
#error "Not Support OS"
#endif 
	
	return nullptr == handle ? false : true;
}

bool FreeDll(void* handle)
{
#ifdef _WIN64
	HMODULE tmp_handle = reinterpret_cast<HMODULE>(handle);
	if (!FreeLibrary(tmp_handle))
	{
		return false;
	}

#elif __linux__
	if (!dlclose(handle))
	{
		return false;
	}

#elif __APPLE__
#error "Not Support OS"
#else
#error "Not Support OS"
#endif 

	return true;
}

template<typename T>
bool GetDllFunc(T func, void* handle, const string& func_name)
{
	if (nullptr == handle)
	{
		return false;
	}

#ifdef _WIN64
	HMODULE tmp_handle = reinterpret_cast<HMODULE>(handle);
	func = reinterpret_cast<T>(GetProcAddress(tmp_handle, func_name.c_str()));
#elif __linux__
	func = reinterpret_cast<T>(GetProcAddress(handle, func_name.c_str()));
#elif __APPLE__
#error "Not Support OS"
#else
#error "Not Support OS"
#endif 

	return true;
}

bool IsValidIP(const string& ip)
{

}

bool GetLocalTime()
{

}
