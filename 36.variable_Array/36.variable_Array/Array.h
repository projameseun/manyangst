#pragma once

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


 //���� 
 void Destroy(FArray* pArr);


 //����
 void SortArr(FArray* pArr,void(*_SortFunc)(int*,int));
