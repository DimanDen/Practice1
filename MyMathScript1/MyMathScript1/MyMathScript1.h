#include "iostream"
#include <string>
class MyMathScript
{
public: 
	MyMathScript();
	MyMathScript(const std::string & Script);
	//double GetResult(double result);

	std::string Script;
	std::string ReadBasicScript(const std::string & Script);
	std::string ReadScript(std::string Script);
	std::string ReadFunctionInScript(std::string Script);
	std::string ReadBrackets(std::string Script);
	//std::string SearchScript();
	//int MyMathScript::Sum(int a, int b);
};
/*2) ���� ��������� ��������� �� ���� ��� ����� �� �������, �� ���� ������ ����������� �� � ����� �������, ������� �� � ������ � �������� ���� ��,
� ���� ��������� ������, ��� ����������� ����� readScript � �� ���������� ������ �� �������������� � readFunctionInScript, ������� ������� ��� �������,
����� ���������� � readBrackets, ������� ������� ��� ������, ����� � ������� ������� ������� ��������� ������� � ����� � readBasicScript, ������� ��� ������,
��, ��� ����������� ������. �� ������ ��� ������� �� ������ ������ � ���� ������ ������ ���������� �� ������ ������� � �������� - �.�. ������ �� ������
 ���������� ��� �� ��� �� ������ ������� ��������� ������� ����, ��� ������ ������ � ���������� � ����������� ����������. */

/*������ ���� printf � ��������� ������ ������ ���� �� ������, ��� printf � ����� ����� ���������� ������ ���� � main, �� � ��� ����������� ���������� � �������� �� �����
 � ��� �� ������� �������� ��������� ���� ������ ���������� � ������ ������� getResult*/