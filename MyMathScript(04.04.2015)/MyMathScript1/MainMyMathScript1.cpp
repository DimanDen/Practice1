#include "MyMathScript1.h"



int main()
{
	MyMathScript myscript;
	std::string input = "2+31*25+4";
	std::cout<<input<<std::endl;
	std::cout<<std::endl;
	myscript.ReadScript(input); 
	printf("Sum = %f\n",myscript.GetResult());
	std::cin.get();
}

//������������ ������� ASCII