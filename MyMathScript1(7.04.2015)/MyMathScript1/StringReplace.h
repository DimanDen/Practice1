#include "iostream"
#include <string>

std::string StringRep(int IndexLeft, int IndexRight, std::string str, std::string strReplace) 
{
	std::string StrHelpRep; //������, � ������� ������� ����� ����������� ������

	for (unsigned int i = 0; i < str.length(); i++) //���� ���� �� ������ �� ����� ������� ������
	{
		if ( i < IndexLeft || i > IndexRight) //���� �� �� ����� �� ���� �����, ����� ���� ��������, �� ������ �������� ������� ������ �� ���������������
		{
			StrHelpRep += str[i];
		}
		else
		{
			for (unsigned int j = 0; j < strReplace.length(); j++) //���� ����� �� ���� �����, ����� ���� ��������, �� �������� �� ��������������� ������ ���� ������ � �����������
			{
				StrHelpRep += strReplace[j];
			}
			i = IndexRight; //����� ����, ��� �������� �����������, ���� ������, ������� ������ �� ���������������
		}
	}
	str = StrHelpRep;
	return str;
}