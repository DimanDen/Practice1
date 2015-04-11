#include "MyMathScript1.h"
#include "StringConvert.h"
#include "StringReplace.h"


MyMathScript::MyMathScript() : result(0)
{
}

MyMathScript::MyMathScript(const std::string & copyScript)
{
	ReadScript(copyScript);
}

std::string MyMathScript::ReadScript(const std::string & Script)  //�������, ������������ ������ �� ��������������. �.�. ������ ����� �������� ����� ������ �������, �� ������� � ��� "const"
{
	ReadFunctionInScript(Script);
	return Script;
}

std::string MyMathScript::ReadFunctionInScript(const std::string & Script) //������� ���������� ��������� ���������� (sin, cos ...)
{
	ReadBrackets(Script);
	return Script;
}

std::string MyMathScript::ReadBrackets(const std::string & Script) //������� ����������� ������ � ���������
{
	ReadOperators(Script);
	return Script;
}

std::string MyMathScript::ReadOperators(const std::string & Script) //������� ���������� �������� ���������, �������...
{
	std::string Script1 = Script;
	double operand1;  //������ ������� � �������� ����
	double operand2;  //������ ������� � �������� ����
	double ResultOp = 0; //��������� �������� � �������� ����
	int IndexReplaceLeft = -1; //����� ������, � �������� ����� ���������� ������� ������, ������� �������� ��������� ��������
	int IndexReplaceRight; //������ ������
	std::string StrResultOp; //������� ������ � ���� �������� ��������� � ������� ����, �����, � ����� �������� ������ ���������

	for (unsigned int i = 0; i < Script1.length(); i++)
	{
		operand1 = 0;
		operand2 = 0;
		if (Script1[i] == '+' || Script1[i] == '-') //���� ���������� �� �������� �������� ��� ���������, �� ���������� ������, �� ������� ���������
		{
			IndexReplaceLeft = i;
		}
		else if(Script1[i] == '*' || Script1[i] == '/') //���� ���������� �� �������� ��������� ��� �������
		{
			for (unsigned int j = IndexReplaceLeft+1; j < i; j++) //� �������, ������� �������� ����� (��� ���� �� ����������, �� �� ��������� ����� -1) �������� ��������� ������� �� ���������
			{
				StrResultOp += Script1[j];
			}
			operand1 = StringConv<double>(StrResultOp); //��������� ������ ������� �� ������ � �����
			StrResultOp = "";
			for (unsigned int j = i+1; j < Script1.length(); j++) //� ������� ��������� ���� �� ����� ������ � ��������� ������ �������, ���� �������� ��������� ��������, �� ����������� ������
			{
				if(Script1[j] == '+' || Script1[j] == '-' || Script1[j] == '*' || Script1[j] == '/')
				{
					IndexReplaceRight = j-1;
					break;
				}
				else if(j == Script1.length()-1) //���� �� ��������� ������ ��������, � ����� �� ����� ������
				{
					IndexReplaceRight = j;
				}
				StrResultOp += Script1[j];
			}
			operand2 = StringConv<double>(StrResultOp); //��������� ������ ������� �� ������ � �����
			StrResultOp = "";
			if(Script1[i] == '*') //���������� ��������������� �������� ��� ���������� � �������� �������
			{
				ResultOp = operand1 * operand2;
			}
			else
			{
				ResultOp = operand1 / operand2;
			}
			StrResultOp = std::to_string(static_cast<long double>(ResultOp) ); //���������� ��������� � ������
			Script1 = StringRep(IndexReplaceLeft+1, IndexReplaceRight, Script1, StrResultOp); //�������������� ������. ������ ������ �������� ������� ��� ��������� ����� �����
			StrResultOp = "";
			ResultOp = 0;
			i = IndexReplaceLeft; //"���������� ������� �����, ����� ������ �� ����������
		}
	}
	ReadBasicScript(Script1); //�������� ���������� ������ � ���������� �������� � ��������� � ������� ��� ��������� ����������� ����������
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