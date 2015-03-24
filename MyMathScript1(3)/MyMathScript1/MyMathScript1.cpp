#include "MyMathScript1.h"
#include <vector>
#include <sstream>
/*MyMathScript::MyMathScript()
{};*/

void MyMathScript::ReadScript(std::string Script)
{
	bool flag = true;
	for (int i = 0; i < Script.length(); i++)
	{
		if (Script[i] > 39 && Script[i] < 43 || Script[i] == 47) //�������� �� ������� � ��������� ������ �������� ����� �������� � ���������
		{
			flag = false;
		}
	}
	if(flag == true)
	{
		ReadSimpleScript(Script);
	}
};


std::string MyMathScript::ReadSimpleScript(std::string Script)
{
	int int1; //����������, �������� � ���� ��������� � �������� ����
	int int2; 
	std::string strint;
	

	int sum = 0; //����������, �������� � ���� �������� �����
	for (int i = 0; i < Script.length(); i++)
	{
		int1 = 0; //����� ������ ��������� ����� �������� ���������
		int2 = 0;
		strint = "";
		if (Script[i] == '+') 
		{
			for (int j = i+1; j < Script.length(); j++)
			{
				if(Script[j] > 47 && Script[j] < 57 || Script[j] == 45) //�������� �� ��, ��� ������ �������� ������ ��� ������ "-"
				{
					strint = strint + Script[j];
					//f++;
				}
				else
				{
					break; //���� ��������� ������ �� ������������ ����� ����������, �� ������� �� �����
				}
			}
			std::istringstream ss(strint);
			ss>>int1;
			strint = "";
			for (int k = i-1; k>-1; --k)
			{
				if(Script[k] > 46 && Script[k] < 58 && sum == 0)
				{
					strint = strint + Script[k];
					strrev(&strint[k]);
				}
				else if(sum != 0) //���� ����� �����-�� ���� ��������� ��� ���� ����������, �� �������� ������� ��������� ������������ � ���� ����� 
				{
					int2 = sum;
					break;
				}
				else
				{
					break;
				}
			}
			if(sum == 0) //���� ����������� ����� �����-�� ���������, �� ��� ������������� ����� ��������� ������ ��������
			{
				std::istringstream ss(strint);
				ss>>int2;
			}
			sum = Sum(int1,int2); 
		}
	}
	return Script;
};

int MyMathScript::Sum(int a, int  b)
{
	//std::cout<<( a + b );
	printf("%d + %d = %d",a,b,a+b);
	std::cout<<std::endl;
	return ( a + b );
};
