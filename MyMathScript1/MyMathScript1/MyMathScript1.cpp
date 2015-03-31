#include "MyMathScript1.h"
#include <vector>
#include "StringConvert.h"

MyMathScript::MyMathScript()
{
}

MyMathScript::MyMathScript(const std::string & Script)
{
}

std::string MyMathScript::ReadScript(std::string Script) 
{
	ReadFunctionInScript(Script);
	return Script;
}

std::string MyMathScript::ReadFunctionInScript(std::string Script)
{
	ReadBrackets(Script);
	return Script;
}

std::string MyMathScript::ReadBrackets(std::string Script)
{
	ReadBasicScript(Script);
	return Script;
}

std::string MyMathScript::ReadBasicScript(const std::string & Script)
{
	double result = 0; //�������������� ��������
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
		if(Script[i] != '+' && Script[i] != '-') //���� �� "����������" ����� �� �����. (�������� ����� �� ���������: ����)
		{
			StrSummand +=Script[i];
			if (Script[i+1] == '+' || Script[i+1]  == '-' || i == (Script.length()-1))
			{
				result += StringConv<double>(sign+StrSummand); //������� ��������� � �������� ���. � �������� ��������� ������� ��������� ������, � ������� ���������� ���� � �����.
				StrSummand = "";
				//printf("Sum = %f\n",result);
				sign = '+'; //������ �� ��������� ������������ ��������
			}
		}
	}
	//printf("Result = %f",result);
	return Script;
}

/*double MyMathScript::GetResult(double result)
{
	//printf("Result = %f",result);
	return result;
}*/