#include "MyMathScript1.h"
#include "StringConvert.h"
#include "StringReverse.h"

MyMathScript::MyMathScript()
{
}

MyMathScript::MyMathScript(const std::string & Script)
{
}

std::string MyMathScript::ReadScript(std::string Script)  //Функция, отправляющая строку на преобразование. Т.к. строка будет меняться входе работы функции, то написал её без "const"
{
	ReadFunctionInScript(Script);
	return Script;
}

std::string MyMathScript::ReadFunctionInScript(std::string Script) //Функция выполнения словесных операторов (sin, cos ...)
{
	ReadBrackets(Script);
	return Script;
}

std::string MyMathScript::ReadBrackets(std::string Script) //Функция определения скобок в выражении
{
	ReadOperators(Script);
	return Script;
}

std::string MyMathScript::ReadOperators(std::string Script) //Функция выполнения операций умножения, деления...
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

std::string MyMathScript::ReadBasicScript(const std::string & Script) //Функция подсчета простого выражения, содержащего операции сложения и вычитания
{
	result = 0; //Результирующее значение
	std::string StrSummand; 
	char sign = '+'; //По умолчанию значение числа полажительно

	for (unsigned int i = 0; i < Script.length(); i++)
	{
		if (Script[i] == '+') //Проверяется знак числа. Меняется в соответствии с математическими правилами.
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
		else if(Script[i] == '-') //Проверяется знак числа. Меняется в соответствии с математическими правилами.
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
		if(Script[i] != '+' && Script[i] != '-') //Если мы "наткнулись" не на знаки.
		{
			StrSummand +=Script[i];
			if (Script[i+1] == '+' || Script[i+1]  == '-' || i == (Script.length()-1)) //Если символы, обознащающие цифры числа, закончились, то переводим строку в числовой тип
			{
				result += StringConv<double>(sign+StrSummand); //Перевод параметра в числовой тип. В качестве аргумента функции выступает строка, в которой содержится знак и число.
				StrSummand = "";
				sign = '+'; //Ставим по умолчанию положительно значение
			}
		}
	}
	return Script;
}

double MyMathScript::GetResult() //Функция вывода результата
{
	return result;
}