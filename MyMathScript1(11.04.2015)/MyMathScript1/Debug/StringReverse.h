#include "iostream"
#include <string>

std::string StringRev(std::string str) 
{
	std::string StrHelpRev; //Строка, с помощью которой будем производить "реверс"
	for (unsigned int i = 0; i < str.length(); i++)
	{
		StrHelpRev += str[str.length()-i-1]; //Записываем в спомогательную строку символы в обратном порядке из входной строки
	}
	str = StrHelpRev; 
	return str;
}