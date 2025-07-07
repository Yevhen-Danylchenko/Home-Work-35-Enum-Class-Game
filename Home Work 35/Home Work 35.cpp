// Home Work 35.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>

#include "MyFuncInterface.h"

namespace Alias = MyFunctionInterface;

int main()
{    
    setlocale(LC_ALL, "ukr");

	Alias::MyFunc();

    return 0;

}


