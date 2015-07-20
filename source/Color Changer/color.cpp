#include "SDK\amx\amx.h"
#include "SDK\plugincommon.h"
#include <errno.h>
#include <direct.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


typedef void(*logprintf_t)(char* format, ...);


logprintf_t logprintf;
extern void *pAMXFunctions;


cell AMX_NATIVE_CALL SetConsoleColor(AMX* amx, cell* params)
{
	int
		len = NULL,
		ret = NULL;

	cell *addr = NULL;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;

		char* text = new char[len];
		amx_GetString(text, addr, 0, len);

		char buff[100];
		snprintf(buff, sizeof(buff), "color %s", text);

		delete[] text;
		return system(buff);
	}

	return 0;
}

cell AMX_NATIVE_CALL systemEx(AMX* amx, cell* params)
{
	int
		len = NULL,
		ret = NULL;

	cell *addr = NULL;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;

		char* text = new char[len];
		amx_GetString(text, addr, 0, len);

		system(text);
		delete[] text;
	}
	return 1;
}

cell AMX_NATIVE_CALL cleanConsole(AMX* amx, cell* params)
{
	system("CLS");
	return 1;
}

cell AMX_NATIVE_CALL getDirectory(AMX* amx, cell* params)
{
	char cwd[1024];
	if (_getcwd(cwd, sizeof(cwd)) != NULL)
	{
		int slotid = params[1];

		cell* return_str;
		amx_GetAddr(amx, params[1], &return_str);
		amx_SetString(return_str, cwd, 0, 0, 1024);
	}
	else return 0;
}

cell AMX_NATIVE_CALL strcopy(AMX* amx, cell* params)
{
	int
		len = NULL,
		ret = NULL;

	cell *addr = NULL;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;

		char* text = new char[len];
		amx_GetString(text, addr, 0, len);

		cell* return_str;
		amx_GetAddr(amx, params[2], &return_str);
		amx_SetString(return_str, text, 0, 0, 1024);
		delete[] text;
	}

	return 1;
}

cell AMX_NATIVE_CALL printfEx(AMX* amx, cell* params)
{
	int
		len = NULL,
		ret = NULL;

	cell *addr = NULL;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;

		char* text = new char[len];
		amx_GetString(text, addr, 0, len);

		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);;
		SetConsoleTextAttribute(hCon, params[2]);

		logprintf(text);
		SetConsoleTextAttribute(hCon, 14);
		delete[] text;
	}

	return 1;
}

cell AMX_NATIVE_CALL setTextColor(AMX* amx, cell* params)
{
	int
		len = NULL,
		ret = NULL;

	cell *addr = NULL;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;

		char* text = new char[len];
		amx_GetString(text, addr, 0, len);

		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);;
		SetConsoleTextAttribute(hCon, params[2]);
	}

	return 1;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	logprintf(" * Console color & command executer loaded.");
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf(" *  console color & command executed unloaded.");
}

AMX_NATIVE_INFO PluginNatives[] =
{
	{ "SetConsoleColor", SetConsoleColor },
	{ "systemEx", systemEx },
	{ "getDirectory", getDirectory },
	{ "cleanConsole", cleanConsole },
	{ "strcopy", strcopy },
	{ "printfEx", printfEx },
	{ "setTextColor", setTextColor }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return amx_Register(amx, PluginNatives, -1);
}


PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	return AMX_ERR_NONE;
}