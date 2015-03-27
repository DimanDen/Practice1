#include "iostream"
#include <string>
#include <sstream>

template <typename T>
T StringConv(const std::string & str) 
{
    T summand1;
	std::istringstream ss(str);
	ss >> summand1;
	return summand1;
}
	
