#include "iostream"
#include <string>

std::string DeleteSpaces(std::string StrIncorrect) 
{
	for (unsigned int i = 0; i < StrIncorrect.length(); i++) //���� ���� �� ������ �� ����� ������� ������
	{
		if (StrIncorrect[i] == ' ')
		{
			remove(&StrIncorrect[i]);
		}
	}
	return StrIncorrect;
}