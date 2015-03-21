#include "MyMathScript1.h"

/*MyMathScript::MyMathScript()
{};*/


std::string MyMathScript::ReadSimpleScript(std::string Script)
{
	int int1;
	int int2;
	int sum = 0;
	for (int i = 0; i < Script.length(); i++)
	{
		int1 = 0;
		int2 = 0;
		if (Script[i] == '+')
		{
			for (int j = i+1; j < Script.length(); j++)
			{
				if(Script[j] != '+')
				{
					int1 = int1 + int(Script[j]);
				}
				else
				{
					break;
				}
			}
			for (int k = i-1; k>-1; --k)
			{
				if(Script[k] != '+' && sum == 0)
				{
					int2 = int2 + int(Script[k]);
				}
				else if(sum != 0)
				{
					int2 = sum;
				}
				else
				{
					break;
				}
				if(k == 0)
				{
					break;
				}
			}
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
