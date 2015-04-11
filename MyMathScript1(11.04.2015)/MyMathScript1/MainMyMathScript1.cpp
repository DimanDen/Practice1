#include "MyMathScript1.h"



int main()
{
	MyMathScript myscript;

	std::string StrInput; 
	std::cin >> StrInput;
	std::string input = StrInput;
	//std::cout<<input<<std::endl;
	std::cout<<std::endl;
	myscript.ReadScript(input); 
	printf("Sum = %f\n",myscript.GetResult());
	
	std::cin >> StrInput;
}

//Используется система ASCII
//2+31*25+4+2*3-6/3
//5+10*5+5+2*3-80/20
//22*3-6+144/12/2