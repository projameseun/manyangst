#include <iostream>
#define MAXSIZE 10

struct FArray
{
	int* pInt;

	size_t iSize;
	size_t iMaxSize;

};
//�ʱ�ȭ
void InitArr(FArray* pArr);
//�߰�
void PushBack(FArray* pArr, int _iData);

//���Ҵ�
void Reallocate(FArray* pArr);


void InitArr(FArray* pArr)
{
	pArr->pInt = (int*)malloc(sizeof(int) * 2);
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


int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//�����迭 

	/*int a = 100;

	int arr[a] = {};*/

	FArray vArr = {};

	InitArr(&vArr);

	for (int i = 0; i < 50; ++i)
	{
		PushBack(&vArr, rand() % 1000);
	}

	for (int i = 0; i < vArr.iSize; ++i)
	{
		std::cout << vArr.pInt[i] << std::endl;
	}



	int a = 0;





	return 0;
}