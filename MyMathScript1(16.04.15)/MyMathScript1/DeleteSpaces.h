#include "iostream"
#include <string>
#include <algorithm>
#include <iostream>


std::string DeleteSpaces(std::string StrIncorrect) 
{
	std::string StrCorrect;
    remove_copy(StrIncorrect.begin(), StrIncorrect.end(), back_inserter(StrCorrect), ' ');
	return StrCorrect;
}