#include "MyMathScript1.h"
#include "StringConvert.h"

MyMathScript::MyMathScript()
{
}

MyMathScript::MyMathScript(const std::string & Script)
{
}

std::string MyMathScript::ReadScript(std::string Script)  //�������, ������������ ������ �� ��������������. �.�. ������ ����� �������� ����� ������ �������, �� ������� � ��� "const"
{
	ReadFunctionInScript(Script);
	return Script;
}

std::string MyMathScript::ReadFunctionInScript(std::string Script) //������� ���������� ��������� ���������� (sin, cos ...)
{
	ReadBrackets(Script);
	return Script;
}

std::string MyMathScript::ReadBrackets(std::string Script) //������� ����������� ������ � ���������
{
	ReadOperators(Script);
	return Script;
}

std::string MyMathScript::ReadOperators(std::string Script) //������� ���������� �������� ���������, �������...
{
	ReadBasicScript(Script);
	return Script;
}

std::string MyMathScript::ReadBasicScript(const std::string & Script) //������� �������� �������� ���������, ����������� �������� �������� � ���������
{
	result = 0; //�������������� ��������
	std::string StrSummand; 
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
		if(Script[i] != '+' && Script[i] != '-') //���� �� "����������" �� �� �����.
		{
			StrSummand +=Script[i];
			if (Script[i+1] == '+' || Script[i+1]  == '-' || i == (Script.length()-1)) //���� �������, ������������ ����� �����, �����������, �� ��������� ������ � �������� ���
			{
				result += StringConv<double>(sign+StrSummand); //������� ��������� � �������� ���. � �������� ��������� ������� ��������� ������, � ������� ���������� ���� � �����.
				StrSummand = "";
				sign = '+'; //������ �� ��������� ������������ ��������
			}
		}
	}
	return Script;
}

double MyMathScript::GetResult() //������� ������ ����������
{
	return result;
}