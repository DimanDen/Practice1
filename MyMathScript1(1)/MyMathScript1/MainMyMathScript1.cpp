#include "MyMathScript1.h"



int main()
{
	MyMathScript myscript;
	std::string input = "25+236+1";
	myscript.ReadSimpleScript(input);

	//std::cout<<s; myscript.Sum(s[1],s[3]); //Система ASCII
	std::cin.get();
}