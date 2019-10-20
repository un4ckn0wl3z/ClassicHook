// ClassicHook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>

double  function(double arg)
{
	std::cout << "Function: Much easier to find me this way! " << arg << std::endl;
	return arg;
}

void  function2()
{
	std::cout << "Function2: This is function2." << std::endl;

}


int main()
{
	for(;;)
	{
		Sleep(2500);
		function(3.14);
		Sleep(2500);
		function2();
		
	}

	return 0;

}


















