#include "MyMathScript1.h"
#include <vector>
/*MyMathScript::MyMathScript()
{};*/


std::string MyMathScript::ReadSimpleScript(std::string Script)
{
	int int1;
	int int2;
	int t = 0;
	std::vector<char> CharVector;
	char strscript[] = "0";
	char strscript1[] = "0";
	char a[] = "0";
	int sum = 0;
	for (int i = 0; i < Script.length(); i++)
	{
		int1 = 0;
		int2 = 0;
		//strscript[i] = "";
		if (Script[i] == '+')
		{
			for (int j = i+1; j < Script.length(); j++)
			{
				if(Script[j] != '+')
				{
					strscript[t] = Script[j];
					t++;
				}
				else
				{
					break;
				}
			}
			int1 = atoi(strscript);
			t=0;
			for (int k = i-1; k>-1; --k)
			{
				if(Script[k] != '+' && sum == 0)
				{
					strscript[t] = Script[k];
					t++;
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

		/*	for (int l = 0; l<strlen(strscript1); l++)
			{
				a[l] = strscript1[l];
				strscript1[strlen(strscript1)-l] = a[l];
			}*/

			int2 = atoi(strscript1);
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
