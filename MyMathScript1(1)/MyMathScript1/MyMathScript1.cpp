#include "MyMathScript1.h"

/*MyMathScript::MyMathScript()
{};*/


std::string MyMathScript::ReadSimpleScript(std::string Script)
{
	int int1;
	int int2;
	std::string strscript;
	int sum = 0;
	for (int i = 0; i < Script.length(); i++)
	{
		int1 = 0;
		int2 = 0;
		strscript = "";
		if (Script[i] == '+')
		{
			int1 = int1 + atoi(&Script[i+1]);

			if(sum != 0)
			{
				int2 = sum;
			}

			int2 = int2 + atoi(&Script[i-1]);

			sum = Sum(int1,int2);
		}
	}
	return Script;
};

int MyMathScript::Sum(int a, int  b)
{
	std::cout<<( a + b );
	std::cout<<std::endl;
	return ( a + b );
};
