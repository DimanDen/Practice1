#include "iostream"
#include <string>

std::string StringRep(int IndexLeft, int IndexRight, std::string str, std::string strReplace) 
{
	std::string StrHelpRep; //—трока, с помощью которой будем производить замену

	for (unsigned int i = 0; i < str.length(); i++) //÷икл пока не дойдем до конца входной строки
	{
		if ( i < IndexLeft || i > IndexRight) //≈сли мы не дошли до того места, когда пора замен€ть, то просто копируем входную строку во вспомогательную
		{
			StrHelpRep += str[i];
		}
		else
		{
			for (unsigned int j = 0; j < strReplace.length(); j++) //≈сли дошли до того места, когда надо замен€ть, то копируем во вспомогательную строку нашу строку с результатом
			{
				StrHelpRep += strReplace[j];
			}
			i = IndexRight; //ѕосле того, как заменили необходимое, идем дальше, копиру€ строку во вспомогательную
		}
	}
	str = StrHelpRep;
	return str;
}