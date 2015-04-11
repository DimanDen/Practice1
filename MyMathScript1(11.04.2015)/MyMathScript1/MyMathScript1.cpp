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

std::string MyMathScript::ReadScript(const std::string & Script)  //Функция, отправляющая строку на преобразование. Т.к. строка будет меняться входе работы функции, то написал её без "const"
{
	ReadFunctionInScript(Script);
	return Script;
}

std::string MyMathScript::ReadFunctionInScript(const std::string & Script) //Функция выполнения словесных операторов (sin, cos ...)
{
	ReadBrackets(Script);
	return Script;
}

std::string MyMathScript::ReadBrackets(const std::string & Script) //Функция определения скобок в выражении
{
	ReadOperators(Script);
	return Script;
}

std::string MyMathScript::ReadOperators(const std::string & Script) //Функция выполнения операций умножения, деления...
{
	std::string Script1 = Script;
	double operand1;  //первый операнд в числовом виде
	double operand2;  //второй операнд в числовом виде
	double ResultOp = 0; //Результат операции в числовом виде
	int IndexReplaceLeft = -1; //Левый индекс, с которого будет начинаться вставка строки, которая содержит результат операции
	int IndexReplaceRight; //Правый индекс
	std::string StrResultOp; //Сначала хранит в себе значения операндов в строков типе, затем, в конце итерации хранит результат

	for (unsigned int i = 0; i < Script1.length(); i++)
	{
		operand1 = 0;
		operand2 = 0;
		if (Script1[i] == '+' || Script1[i] == '-') //Если наткнулись на операцию сложения или вычитания, то записываем индекс, на котором находимся
		{
			IndexReplaceLeft = i;
		}
		else if(Script1[i] == '*' || Script1[i] == '/') //Если наткнулись на операцию умножения или деления
		{
			for (unsigned int j = IndexReplaceLeft+1; j < i; j++) //С индекса, который записали ранее (или если не записывали, он по умолчанию равен -1) начинаем считывать операнд до оператора
			{
				StrResultOp += Script1[j];
			}
			operand1 = StringConv<double>(StrResultOp); //Переводим первый операнд из строки в число
			StrResultOp = "";
			for (unsigned int j = i+1; j < Script1.length(); j++) //С индекса оператора идем до конца строки и считываем второй операнд, если втретили следующую операцию, то заканчиваем запись
			{
				if(Script1[j] == '+' || Script1[j] == '-' || Script1[j] == '*' || Script1[j] == '/')
				{
					IndexReplaceRight = j-1;
					break;
				}
				else if(j == Script1.length()-1) //Если не встретили другую операцию, а дошли до конца строки
				{
					IndexReplaceRight = j;
				}
				StrResultOp += Script1[j];
			}
			operand2 = StringConv<double>(StrResultOp); //Переводим второй операнд из строки в число
			StrResultOp = "";
			if(Script1[i] == '*') //Производим соответствующую операцию над операндами в числовом формате
			{
				ResultOp = operand1 * operand2;
			}
			else
			{
				ResultOp = operand1 / operand2;
			}
			StrResultOp = std::to_string(static_cast<long double>(ResultOp) ); //Записываем результат в строку
			Script1 = StringRep(IndexReplaceLeft+1, IndexReplaceRight, Script1, StrResultOp); //Переопределяем скрипт. Теперь вместо операции деления или уиножения стоит число
			StrResultOp = "";
			ResultOp = 0;
			i = IndexReplaceLeft; //"Отматываем счетчик назад, чтобы ничего не пропустить
		}
	}
	ReadBasicScript(Script1); //Передаем измененный скрипт с операциями сложения и вычитания в функцию для получения дальнейшего результата
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