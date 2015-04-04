#include "iostream"
#include <string>

std::string StringRev(std::string str) 
{
	std::string StrHelpRev;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		StrHelpRev += str[str.length()-i-1];
	}
	str = StrHelpRev;
	return str;
}