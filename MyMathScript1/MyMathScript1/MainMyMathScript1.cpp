#include "MyMathScript1.h"



int main()
{
	MyMathScript myscript;
	std::string input = "31.3-+25.2+1";
	std::cout<<input<<std::endl;
	std::cout<<std::endl;
	myscript.ReadScript(input);
	std::cin.get();
}

//Используется система ASCII