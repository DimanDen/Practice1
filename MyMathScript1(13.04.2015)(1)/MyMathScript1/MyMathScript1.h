#include "iostream"
#include <string>
class MyMathScript
{
public: 
	MyMathScript();
	MyMathScript(const std::string & Script);
	
	std::string Script;
	double result;
	int IndexLeftBracket;
	int IndexRightBracket;

	double GetResult();
	std::string ReadScript(const std::string & Script);
	std::string ReadFunctionInScript(const std::string & Script);
	std::string ReadBrackets(const std::string & Script);
	std::string ReadOperators(const std::string & Script, const std::string & ScriptBasic);
	std::string ReadBasicScript(const std::string & Script, const std::string & ScriptBasic);
};

/*Надо составить структуру по типу той схемы из функций, то есть сейчас выполняется всё в одной функции, которая всё и делает и рекурсит себя же,
а надо прописать логику, что запускается некий readScript и он отправляет строку на преобразование в readFunctionInScript, которая считает все функции,
потом отправляет в readBrackets, которая считает все скобки, потом в функцию которая считает умножение деление и потом в readBasicScript, которая уже делает,
то, что реализовано сейчас. Но первые три функции на данный момент у тебя просто должны возвращать ту строку которую и получили - т.е. ничего не делать
 Получается что ты как бы должен сначала составить обложку того, что будешь делать и наполняешь её содержанием постепенно. */