#include "MyMathScript1.h"
#include <vector>
#include "StringConvert.h"

MyMathScript::MyMathScript()
{
}

MyMathScript::MyMathScript(const std::string & Script)
{

}

void MyMathScript::ReadScript(std::string Script)
{
	bool flag = true;
	for (unsigned int i = 0; i < Script.length(); i++)
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

std::string MyMathScript::ReadSimpleScript(const std::string & Script)
{
	int int1; //Переменная, хранящая в себе слагаемое в числовом типе
	int int2; 
	std::string strint;

	int sum = 0; //Переменная, хранящая в себе значение суммы
	for (int i = 0; i < Script.length(); i++)
	{
		int1 = 0; //Перед каждым подсчетом суммы обнуляем слогаемые
		int2 = 0;
		strint = "";
		if (Script[i] == '+') 
		{
			for (int j = i+1; j < Script.length(); j++)
			{
				if(Script[j] > 47 && Script[j] < 57 || Script[j] == 45) //Проверка на то, что символ является цифрой или знаком "-"
				{
					strint = strint + Script[j];
					//f++;
				}
				else
				{
					break; //Если встретили символ не обозначающий цифру слагаемого, то выходим из цикла
				}
			}
			
			StringConv<int>(strint);
			strint = "";
			for (int k = i-1; k>-1; --k)
			{
				if(Script[k] > 46 && Script[k] < 58 && sum == 0)
				{
					strint = strint + Script[k];
					//strrev(&strint[k]);
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
				StringConv<int>(strint);
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
