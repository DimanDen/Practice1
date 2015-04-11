#include "MyMathScript1.h"



int main()
{
	MyMathScript myscript;
	MyMathScript myscript1 = myscript;

	std::string str; 
	std::cin >> str;
	std::string input = str;//"5+10*5+5+2*3-80/20";
	std::cout<<input<<std::endl;
	std::cout<<std::endl;
	myscript.ReadScript(input); 
	printf("Sum = %f\n",myscript.GetResult());
	
	std::cin >> str;
}

//Используется система ASCII
//2+31*25+4+2*3-6/3
//5+10*5+5+2*3-80/20
//22*3-6+144/12/2