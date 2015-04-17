#include "iostream"
#include <string>
#include <sstream>

template <typename T>
T StringConv(const std::string & str) 
{
    T summand;
	std::istringstream ss(str);
	ss >> summand;
	return summand;
}
	
