#include <iostream>
#include "Array.h"
#include <time.h>
#define MAXSIZE 10

struct FFunction
{
public:
	void Func1()
	{
		std::cout << "Func1" << std::endl;
	}
	void Func2()
	{
		std::cout << "Func2" << std::endl;
	}
	void Func3()
	{
		std::cout << "Func3" << std::endl;
	}
	void Func4()
	{
		std::cout << "Func4" << std::endl;
	}
	void Func5()
	{
		std::cout << "Func1" << std::endl;
	}
	

	int Minus(int a, int b)
	{
		return a - b;
	}

};


void OutPut()
{
	std::cout << "Out Put" << std::endl;

	
}

void Test()
{
	std::cout << "Test" << std::endl;
}

int Add(int a, int b)
{
	return a + b;
}

void BubbleSort(int* _pData, int _Count)
{
	int iTemp = 0;

	for (int i = 0; i < _Count; ++i)
	{
		for (int j = i + 1; j < _Count; ++j)
		{
			if (_pData[i] > _pData[j])
			{
				iTemp = _pData[i];
				_pData[i] = _pData[j];
				_pData[j] = iTemp;
			}
		}
	}
}


int main()
{
	srand(time(NULL));

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//가별배열 

	/*int a = 100;

	int arr[a] = {};*/

	FArray vArr = {};

	InitArr(&vArr);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&vArr, rand()%100);
	}

	
	
	//정렬
	
	SortArr(&vArr,BubbleSort);


	for (int i = 0; i < vArr.iSize; ++i)
	{
		std::cout << vArr.pInt[i] << std::endl;
	}


	//함수포인터
	//함수의 주소를 가지고 있는것을 말한다.

	void(*pFunc)() = OutPut;
	void(*pFuncTest)() = nullptr;


	pFunc();
	pFuncTest = Test;

	int(*pFuncAdd)(int, int) = Add;

	int a = pFuncAdd(10, 10);

	std::cout << "a = "<< a << std::endl;
	

	void(FFunction:: * pFun1)();

	pFun1 = &FFunction::Func1;

	
	FFunction func1, func2, func3;

	(func1.*pFun1)();
	
	void(FFunction:: * pMagicArray[10])();

	pMagicArray[0] = &FFunction::Func1;
	pMagicArray[1] = &FFunction::Func2;
	pMagicArray[2] = &FFunction::Func3;

	(func1.*pMagicArray[0])();
	(func1.*pMagicArray[1])();
	(func1.*pMagicArray[2])();

	int(FFunction:: * pMinus)(int, int);

	pMinus = &FFunction::Minus;

	(func2.*pMinus)(20, 20);
	


	Destroy(&vArr);

	//int a = 0;





	return 0;
}