#include "MyMathScript1.h"
#include "StringConvert.h"
#include "StringReverse.h"
#include "StringReplace.h"



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
	double operand1;  //первый операнд в числовом виде
	double operand2;  //второй операнд в числовом виде
	double ResultOp = 0; //Результат операции в числовом виде
	int IndexReplaceLeft; //Левый индекс, с которого будет начинаться вставка строки, которая содержит результат операции
	int IndexReplaceRight; //Правый индекс
	std::string StrResultOp; //Сначала хранит в себе значения операндов в строков типе, затем, в конце итерации хранит результат

	for (unsigned int i = 0; i < Script.length(); i++)
	{
		operand1 = 0;
		operand2 = 0;
		if (Script[i] == '*' || Script[i] == '/') //Если наткнулись на умножение и деление
		{
			for (unsigned int j = i+1; j < Script.length(); j++) //Идем вправо и считываем операнд
			{
				if(Script[j] != '+' && Script[j] != '-' && Script[j] != '*' && Script[j] != '/') //Считываем символы, пока не наткнемся на другой знак операции
				{
					StrResultOp += Script[j];
				}
				else 
				{
					IndexReplaceRight = j-1;
					break;
				}
				if(j == Script.length()-1) //Если наткнулись не на операцию, а на конец скрипта
				{
					IndexReplaceRight = j;
					break;
				}
			}

			operand1 = StringConv<double>(StrResultOp); //Переводим первый операнд из строки в число
			StrResultOp = ""; 

			for (int k = i-1; k > -1; --k) //Идем влево и считываем операнд
			{
				if(Script[k] != '+' && Script[k] != '-' && Script[k] != '*' && Script[k] != '/')
				{
					StrResultOp += Script[k];
				}
				else
				{
					IndexReplaceLeft = k+1;
					break;
				}
				if(k == 0) //Если наткнулись не на операцию, а на начало скрипта
				{
					IndexReplaceLeft = k;
					break;
				}
			}
			operand2 = StringConv<double>(StringRev(StrResultOp)); //Переводим второй операнд из строки в число. Перед этим инвертирую строку, где находится второй операнд. Т.к. мы его считывали справа-налево
			if(Script[i] == '*') //Производим соответствующую операцию над операндами в числовом формате
			{
				ResultOp = operand1 * operand2;
			}
			else
			{
				ResultOp = operand2 / operand1;
			}
			StrResultOp = std::to_string(ResultOp); //Записываем результат в строку
			Script = StringRep(IndexReplaceLeft, IndexReplaceRight, Script, StrResultOp); //Переопределяем скрипт. Теперь вместо операции деления или уиножения стоит число
			StrResultOp = "";
			ResultOp = 0;
			i = IndexReplaceLeft; //Чтобы не считывать всю строку заново, присваиваем счетчику значение левого индекса. С которого мы начинали вставлять число вместо операции в функции StringReplac
		}
	}
	ReadBasicScript(Script); //Передаем измененный скрипт с операциями сложения и вычитания в функцию для получения дальнейшего результата
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