#include "MyMathScript1.h"
#include <vector>
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
	std::vector<char> CharVector; //������, �������������� ��� �������� ��������, �� ������� ������� ���������
	int sum = 0; //����������, �������� � ���� �������� �����
	for (int i = 0; i < Script.length(); i++)
	{
		int1 = 0; //����� ������ ��������� ����� �������� ���������
		int2 = 0;
		if (Script[i] == '+') 
		{
			CharVector.clear(); //����� ������������ ���������� ���������� ������� ������

			for (int j = i+1; j < Script.length(); j++)
			{
				if(Script[j] > 47 && Script[j] < 57 || Script[j] == 45) //�������� �� ��, ��� ������ �������� ������ ��� ������ "-"
				{
					CharVector.push_back(Script[j]); //���������� ������, ������� ���������� ����� ����������, � ������ 
				}
				else
				{
					break; //���� ��������� ������ �� ������������ ����� ����������, �� ������� �� �����
				}
			}
			char* number1= new char(CharVector.size()); //��������� ������ ��������, ��� ����, ����� ������������ ����� ����������� � �����.
			for (int j = 0; j < CharVector.size(); j++)
			{
				number1[j] = CharVector[j];
			}
			int1 = atoi(number1);

			CharVector.clear(); //����� ������������ ���������� ���������� ������� ������

			for (int k = i-1; k>-1; --k)
			{
				if(Script[k] > 46 && Script[k] < 58 && sum == 0)
				{
					CharVector.push_back(Script[k]);
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
				char* number2= new char(CharVector.size());
				for (int j = 0; j < CharVector.size(); j++)
				{
					number2[j] = CharVector[CharVector.size()-j-1]; //�.�. ��������� ��������� ������-������, �� ������� ���� �������� � �������� �������.
				}
				int2 = atoi(number2);
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
