#include "iostream"
#include <string>
class MyMathScript
{
public: 
	MyMathScript();
	MyMathScript(const std::string & Script);
	
	std::string Script;
	double result;

	double GetResult();
	std::string ReadScript(std::string Script);
	std::string ReadFunctionInScript(std::string Script);
	std::string ReadBrackets(std::string Script);
	std::string ReadOperators(std::string Script);
	std::string ReadBasicScript(const std::string & Script);
};