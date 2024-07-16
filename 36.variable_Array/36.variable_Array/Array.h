#pragma once

 struct FArray
{
	 int* pInt;

	 size_t iSize;
	 size_t iMaxSize;
	 
};
 //초기화
 void InitArr(FArray* pArr);
 //추가
 void PushBack(FArray* pArr, int _iData);

 //재할당
 void Reallocate(FArray* pArr);


 //삭제 
 void Destroy(FArray* pArr);


 //정렬
 void SortArr(FArray* pArr,void(*_SortFunc)(int*,int));
