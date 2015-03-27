#include "MyMathScript1.h"
#include <vector>
#include "StringConvert.h"

MyMathScript::MyMathScript()
{
}

MyMathScript::MyMathScript(const std::string & Script)
{

}

std::string MyMathScript::ReadSimpleScript(const std::string & Script)
{
	int result = 0; //�������������� ��������
	std::string StrSummand; 
	//std::vector<char> SignVector; 
	char sign = '+'; //�� ��������� �������� ����� ������������

	for (unsigned int i = 0; i < Script.length(); i++)
	{
		if (Script[i] == '+') //����������� ���� �����. �������� � ������������ � ��������������� ���������.
		{
			if(sign == '-')
			{
				sign = '-';
			}
			else
			{
				sign = '+';
			}
		}
		else if(Script[i] == '-') //����������� ���� �����. �������� � ������������ � ��������������� ���������.
		{
			if(sign == '-')
			{
				sign = '+';
			}
			else
			{
				sign = '-';
			}
		}

		//StringConv<int>(strint);
		if(Script[i] > 47 && Script[i] < 58) //���� �� "����������" ����� �� �����. (�������� ����� �� ���������: ����)
		{
			StrSummand +=Script[i];
			if (Script[i+1] == '+' || Script[i+1]  == '-' || i == (Script.length()-1))
			{
				result += StringConv<int>(sign+StrSummand); //������� ��������� � �������� ���. � �������� ��������� ������� ��������� ������, � ������� ���������� ���� � �����.
				StrSummand = "";
				printf("Sum = %d\n",result);
				sign = '+'; //������ �� ��������� ������������ ��������
			}
		}
	}
	printf("Result = %d",result);
	return Script;
}