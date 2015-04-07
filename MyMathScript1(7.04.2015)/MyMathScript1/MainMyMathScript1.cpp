#include "MyMathScript1.h"



int main()
{
	MyMathScript myscript;
	std::string input = "2+5*6+4+2*3-6/3";
	std::cout<<input<<std::endl;
	std::cout<<std::endl;
	myscript.ReadScript(input); 
	printf("Sum = %f\n",myscript.GetResult());
	std::cin.get();
}

//Используется система ASCII
//2+31*25+4+2*3-6/3