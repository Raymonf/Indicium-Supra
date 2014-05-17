#pragma once

#include <utils/windows.h>
#include <utils/namedpipeclient.h>
#include <utils/bitstream.h>

#define EXPORT extern "C" __declspec(dllexport)

#define SERVER_CHECK(retn)	\
if (!IsServerAvailable())	\
{							\
	if (!Init())			\
		return retn;		\
	else					\
		Sleep(100);			\
}							\

bool IsServerAvailable();

EXPORT int  Init();
EXPORT void	SetParam(char *_szParamName, char *_szParamValue);