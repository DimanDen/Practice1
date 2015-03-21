// MyMathScript.cpp: определяет точку входа для консольного приложения.
//

#include "MyMathScript.h"



int main()
{
	MyMathScript myscript;
	std::string input = "2+2";
	myscript.ReadSimpleScript(input);
	std::cin.get();
	std::cout<<myscript.Script.c_str();
	std::cin.get();
}

