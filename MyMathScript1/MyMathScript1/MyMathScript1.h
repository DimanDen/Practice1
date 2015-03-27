#include "iostream"
#include <string>
class MyMathScript
{
public: 
	MyMathScript();
	MyMathScript(const std::string & Script);

	std::string Script;
	std::string ReadSimpleScript(const std::string & Script);
	//void ReadScript(std::string Script);
	//std::string SearchScript();
	//int MyMathScript::Sum(int a, int b);
};