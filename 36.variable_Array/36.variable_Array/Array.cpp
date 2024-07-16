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
	
	//������ �߰� 
	//int[size] = data;
	//*(((*pArr).pInt) + (*pArr).iSize) = _iData;
	//((*pArr).pInt)[(*pArr).iSize] = _iData;
	pArr->pInt[pArr->iSize++] = _iData;
	
	//pArr->iSize++;
}

void Reallocate(FArray* pArr)
{
	//1.���Ҵ�
	int* ptr = (int*)malloc(pArr->iMaxSize * 2 * sizeof(int));

	

	//���� ������ �ִ� �����͸� ���� �Ҵ��� �������� ������ �ش�.
	for (int i = 0; i < pArr->iSize; ++i)
	{
		ptr[i] = pArr->pInt[i];
	}

	//������
	//Heap corruption detected
	//malloc new �Ҵ�� �޸��� �������� ��ū ������ ���������� ���´�.
	//�� ������ �ٷγ����°Ծƴ϶� ���߿����ͼ� ã������� .

		//���� ������ ���� 
	delete[] pArr->pInt;

	pArr->pInt = ptr;

	pArr->iMaxSize *= 2;
}

void Destroy(FArray* pArr)
{
	if (pArr != nullptr)
	{
		delete[] pArr->pInt;
		pArr->iSize = 0;
		pArr->iMaxSize = 0;
	}
}

void SortArr(FArray* pArr,void(*_SortFunc)(int*, int))
{
	/*int iTemp = 0;
	
	for (int i = 0; i < pArr->iSize; ++i)
	{
		for (int j = i + 1; j < pArr->iSize; ++j)
		{
			if (pArr->pInt[i] > pArr->pInt[j])
			{
				iTemp = pArr->pInt[i];
				pArr->pInt[i] = pArr->pInt[j];
				pArr->pInt[j] = iTemp;
			}
		}
	}*/

	_SortFunc(pArr->pInt, pArr->iSize);

}
