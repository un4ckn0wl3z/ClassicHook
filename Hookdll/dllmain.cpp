// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "detours/detours.h"
#include <iostream>
#define ADDRESS 0x401410

double (__cdecl* originalFunction)(double);


double hookedFunction(double a)
{
	std::cout << "original function: argument = " << a << std::endl;
	a = 50.1337;
	return originalFunction(a);
}


BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		originalFunction = (double(__cdecl*)(double))DetourFunction((PBYTE)ADDRESS, (PBYTE)hookedFunction); //Magic
		break;
	}
	return TRUE;
}
