#include "iostream"
#include <string>
class MyMathScript
{
public: 
	std::string Script;
	std::string ReadSimpleScript(std::string Script);
	void ReadScript(std::string Script);
	std::string SearchScript();
	int MyMathScript::Sum(int a, int b);
};