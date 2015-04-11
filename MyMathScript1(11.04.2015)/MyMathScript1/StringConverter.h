#include "iostream"
#include <string>
#include <sstream>

template <typename T>
T StringConv(const std::string & str) 
{
    T val;
	std::istringstream ss(str);
	ss >> val;
	return val;
}
	
