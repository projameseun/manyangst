#include "CArray.h"
#include <assert.h>
#include <iostream>

CArray::CArray()
	:	m_pInt(nullptr),
	m_iCount(0),
	m_iMaxCount(2) //maxsize 설정
{
	m_pInt = new int[2];
}

CArray::~CArray()
{

	if(m_pInt != nullptr)
	{
		delete[] m_pInt;
		m_pInt = nullptr;
	}
}

void CArray::push_back(int _data)
{
	//예외처리
	if (m_iMaxCount <= m_iCount) //size가 maxsize보다 커졌을 때 resize 호출
	{
		//재할당
		resize(m_iMaxCount * 2);
	}

	m_pInt[m_iCount++] = _data;


}

void CArray::resize(int _size) //크기 늘려주기
{
	//m_iMaxCount = 10;
	//예외처리 
	if (m_iMaxCount >= _size)
	{
		//std::cout << "할당할 크기가 MaxCount보다 같거나 작습니다" << std::endl;
		//assert(nullptr);
		throw std::runtime_error("할당할 크기가 MaxCount보다 같거나 작습니다");

		//
		
	}

	int* pTemp = new int[_size];
	

	//기존 공간에 있던 데이터를 새로 할당한 공간으로 복사해 준다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pTemp[i]= m_pInt[i];
	}

	delete[] m_pInt;

	m_pInt = pTemp;
	
	m_iMaxCount = _size;

	std::cout << "MaxCount :" << m_iMaxCount << std::endl;

	
}
//{
//	return m_pInt[_idx];
//}

int& CArray::operator[](int _idx) //연산자
{
	if (_idx < 0 || _idx >= m_iCount)
	{
		throw std::out_of_range("Index out of range");
	}

	return m_pInt[_idx];
}

void CArray::OutPut() // 출력하기
{
	for (int i = 0; i < m_iCount; ++i)
	{
		std::cout << m_pInt[i] << std::endl;
	}
}

void CArray::Delete(int _size)
{
	if (_size < 0 || _size >= m_iCount) {
	/*	std::cout << "유효하지 않음" << std::endl;
		return;*/

		throw std::out_of_range("Index out of Range");
	}

	int* pTemp = new int[m_iCount - 1];

	int k = 0;

	/*for (int i = _size; i < m_iCount - 1; ++i) {
		m_pInt[i] = m_pInt[i + 1];
	}*/

	for (int i = 0; i < m_iCount; ++i)
	{
		if (i == _size)continue;
		pTemp[k++] = m_pInt[i];
	}

	delete[] m_pInt;

	m_pInt = pTemp;


	--m_iCount;

	

	m_iMaxCount = m_iCount;
	
}
