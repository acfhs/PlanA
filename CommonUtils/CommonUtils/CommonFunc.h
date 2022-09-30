#pragma once
#ifndef  __COMMON_FUNC_H__
#define  __COMMON_FUNC_H__

#include "CommonDataDefine.h"

template<typename T>
auto String2T(const string& value)
{
	if (value.empty())
	{
		return T();
	}

	T ret;
	stringstream ss(value);
	ss >> ret;
	return ret;
}


bool StringTWString(wstring& out_wstr, const string& string);


#endif

