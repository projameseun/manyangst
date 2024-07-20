#include "CArray.h"
#include <assert.h>
#include <iostream>

CArray::CArray()
	:	m_pInt(nullptr),
	m_iCount(0),
	m_iMaxCount(2)
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
	if (m_iMaxCount <= m_iCount)
	{
		//재할당
		resize(m_iMaxCount * 2);
	}

	m_pInt[m_iCount++] = _data;


}

void CArray::resize(int _size)
{
	
	//예외처리 
	if (m_iMaxCount >= _size)
	{
		std::cout << "할당할 크기가 MaxCount보다 같거나 작습니다" << std::endl;
		assert(nullptr);

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

//int CArray::operator[](int _idx)
//{
//	return m_pInt[_idx];
//}

int& CArray::operator[](int _idx)
{
	return m_pInt[_idx];
}

void CArray::OutPut()
{
	for (int i = 0; i < m_iCount; ++i)
	{
		std::cout << m_pInt[i] << std::endl;
	}
}

void CArray::Delete(int _size)
{
}
