#include "MyMathScript1.h"



int main()
{
	MyMathScript myscript;
	std::string input = "31+25+1";
	std::cout<<input<<std::endl;
	std::cout<<std::endl;
	myscript.ReadScript(input);
	//myscript.ReadSimpleScript(input);
	std::cin.get();
}

//������������ ������� ASCII