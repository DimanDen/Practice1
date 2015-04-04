#include "MyMathScript1.h"
#include "StringConvert.h"
#include "StringReverse.h"

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
	double operand1;
	double operand2;
	double ResultOp = 0;
	std::string StrResultOp;
	
	for (unsigned int i = 0; i < Script.length(); i++)
	{
		operand1 = 0;
		operand2 = 0;
		if (Script[i] == '*')
		{
			for (unsigned int j = i+1; j < Script.length(); j++)
			{
				if(Script[j] != '+' && Script[j] != '-' && Script[j] != '*' && Script[j] != '/')
				{
					StrResultOp += Script[j];
				}
				else 
				{
					break;
				}
			}

			operand1 = StringConv<double>(StrResultOp);
			StrResultOp = "";

			for (int k = i-1; k > -1; --k)
			{
				if(Script[k] != '+' && Script[k] != '-' && Script[k] != '*' && Script[k] != '/')
				{
					StrResultOp += Script[k];
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
			operand2 = StringConv<double>(StringRev(StrResultOp));
			ResultOp = operand1 * operand2;
			//Script.replace(Script[2,3],ResultOp);
			StrResultOp = "";
		}
	}
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