#include <iostream>
#include "Array.h"

void InitArr(FArray* pArr)
{
	pArr->pInt = (int*)malloc(sizeof(int)* 2);
	pArr->iSize = 0;
	pArr->iMaxSize = 2;

}

void PushBack(FArray* pArr, int _iData)
{
	if (pArr->iMaxSize <= pArr->iSize)
	{
		//Reallocate
		Reallocate(pArr);
	}
	
	//데이터 추가 
	//int[size] = data;
	//*(((*pArr).pInt) + (*pArr).iSize) = _iData;
	//((*pArr).pInt)[(*pArr).iSize] = _iData;
	pArr->pInt[pArr->iSize++] = _iData;
	
	//pArr->iSize++;
}

void Reallocate(FArray* pArr)
{
	//1.재할당
	int* ptr = (int*)malloc(pArr->iMaxSize * 2 * sizeof(int));

	

	//기존 공간에 있던 데이터를 새로 할당한 공간으로 복사해 준다.
	for (int i = 0; i < pArr->iSize; ++i)
	{
		ptr[i] = pArr->pInt[i];
	}

	//힙에러
	//Heap corruption detected
	//malloc new 할당된 메모리의 영역보다 더큰 영역에 접근했을때 나온다.
	//이 에러가 바로나오는게아니라 나중에나와서 찾기힘들다 .

		//기존 공간은 해제 
	delete[] pArr->pInt;

	pArr->pInt = ptr;

	pArr->iMaxSize *= 2;
}
