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
	std::string ReadScript(const std::string & Script);
	std::string ReadFunctionInScript(const std::string & Script);
	std::string ReadBrackets(const std::string & Script);
	std::string ReadOperators(const std::string & Script);
	std::string ReadBasicScript(const std::string & Script);
};

/*���� ��������� ��������� �� ���� ��� ����� �� �������, �� ���� ������ ����������� �� � ����� �������, ������� �� � ������ � �������� ���� ��,
� ���� ��������� ������, ��� ����������� ����� readScript � �� ���������� ������ �� �������������� � readFunctionInScript, ������� ������� ��� �������,
����� ���������� � readBrackets, ������� ������� ��� ������, ����� � ������� ������� ������� ��������� ������� � ����� � readBasicScript, ������� ��� ������,
��, ��� ����������� ������. �� ������ ��� ������� �� ������ ������ � ���� ������ ������ ���������� �� ������ ������� � �������� - �.�. ������ �� ������
 ���������� ��� �� ��� �� ������ ������� ��������� ������� ����, ��� ������ ������ � ���������� � ����������� ����������. */