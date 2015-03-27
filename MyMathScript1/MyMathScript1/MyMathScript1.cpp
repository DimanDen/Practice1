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
	int result = 0; //Результирующее значение
	std::string StrSummand; 
	//std::vector<char> SignVector; 
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

		//StringConv<int>(strint);
		if(Script[i] > 47 && Script[i] < 58) //Если мы "наткнулись" сразу на число. (Значение занка по умолчанию: плюс)
		{
			StrSummand +=Script[i];
			if (Script[i+1] == '+' || Script[i+1]  == '-' || i == (Script.length()-1))
			{
				result += StringConv<int>(sign+StrSummand); //Перевод параметра в числовой тип. В качестве аргумента функции выступает строка, в которой содержится знак и число.
				StrSummand = "";
				printf("Sum = %d\n",result);
				sign = '+'; //Ставим по умолчанию положительно значение
			}
		}
	}
	printf("Result = %d",result);
	return Script;
}