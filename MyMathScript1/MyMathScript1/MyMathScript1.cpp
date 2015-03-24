#include "MyMathScript1.h"
#include <vector>
/*MyMathScript::MyMathScript()
{};*/

void MyMathScript::ReadScript(std::string Script)
{
	bool flag = true;
	for (int i = 0; i < Script.length(); i++)
	{
		if (Script[i] > 39 && Script[i] < 43 || Script[i] == 47) //Проверка на наличие в выражении других операций кроме сложения и вычитания
		{
			flag = false;
		}
	}
	if(flag == true)
	{
		ReadSimpleScript(Script);
	}
};


std::string MyMathScript::ReadSimpleScript(std::string Script)
{
	int int1; //Переменная, хранящая в себе слагаемое в числовом типе
	int int2; 
	std::vector<char> CharVector; //Список, прденазанченый для хранения символов, из которых состоит слагаемое
	int sum = 0; //Переменная, хранящая в себе значение суммы
	for (int i = 0; i < Script.length(); i++)
	{
		int1 = 0; //Перед каждым подсчетом суммы обнуляем слогаемые
		int2 = 0;
		if (Script[i] == '+') 
		{
			CharVector.clear(); //Перед определением слагаемого происходит очистка списка

			for (int j = i+1; j < Script.length(); j++)
			{
				if(Script[j] > 47 && Script[j] < 57 || Script[j] == 45) //Проверка на то, что символ является цифрой или знаком "-"
				{
					CharVector.push_back(Script[j]); //Записываем символ, который определяет цифру слагаемого, в список 
				}
				else
				{
					break; //Если встретили символ не обозначающий цифру слагаемого, то выходим из цикла
				}
			}
			char* number1= new char(CharVector.size()); //Объявляем массив символов, для того, чтобы использовать метод конвертации в число.
			for (int j = 0; j < CharVector.size(); j++)
			{
				number1[j] = CharVector[j];
			}
			int1 = atoi(number1);

			CharVector.clear(); //Перед определением слагаемого происходит очистка списка

			for (int k = i-1; k>-1; --k)
			{
				if(Script[k] > 46 && Script[k] < 58 && sum == 0)
				{
					CharVector.push_back(Script[k]);
				}
				else if(sum != 0) //Если сумма каких-то двух слагаемых уже была подсчитана, то нанешнее всторое слагаемое приравниваем к этой сумме 
				{
					int2 = sum;
					break;
				}
				else
				{
					break;
				}
			}
			if(sum == 0) //Если проводилась сумма каких-то слагаемых, то нет необходимости снова создавать массив символов
			{
				char* number2= new char(CharVector.size());
				for (int j = 0; j < CharVector.size(); j++)
				{
					number2[j] = CharVector[CharVector.size()-j-1]; //Т.к. считывали слагаемое справа-налево, то символы надо записать в обратном порядке.
				}
				int2 = atoi(number2);
			}
			sum = Sum(int1,int2); 
		}
	}
	return Script;
};

int MyMathScript::Sum(int a, int  b)
{
	//std::cout<<( a + b );
	printf("%d + %d = %d",a,b,a+b);
	std::cout<<std::endl;
	return ( a + b );
};
