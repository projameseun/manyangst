#pragma once

#include <assert.h>
#include <iostream>


template<class T>
class CArray
{
private:
	T*		m_pData;
	int		m_iCount;
	int		m_iMaxCount;

public:
	int size()
	{
		return m_iCount;
	}

	int capacity()
	{
		return m_iMaxCount;
	}
	
	T* data()
	{
		return m_pData;
	}
	


public:
	CArray();
	~CArray();

public:
	void push_back(const T& _data);
	void resize(int _size);
	void OutPut();
	void Delete(int _size);

public:
	//int operator[] (int _idx);
	T& operator[] (int _idx);

	class iterator;	//전방선언
	iterator begin();


public:
	//이너클래스
	//반복자 
	class iterator
	{
	private:
		T*		m_pData;		//데이터 시작주소
		int		m_iIdx;			//가리키는 인덱스

	public:
		iterator():
			m_pData(nullptr),
			m_iIdx(-1)
		{
			
		}
		~iterator()
		{

		}

		
	};

};



template<class T>
CArray<T>::CArray(): 
	m_pData(nullptr),
	m_iCount(0),
	m_iMaxCount(2) //maxsize 설정
{
	m_pData = new T[2];
}

template<class T>
CArray<T>::~CArray()
{

	if (m_pData != nullptr)
	{
		delete[] m_pData;
		m_pData = nullptr;
	}
}

template<class T>
void CArray<T>::push_back(const T& _data)
{
	//예외처리
	if (m_iMaxCount <= m_iCount) //size가 maxsize보다 커졌을 때 resize 호출
	{
		//재할당
		resize(m_iMaxCount * 2);
	}

	m_pData[m_iCount++] = _data;
}

template<typename T>
void CArray<T>::resize(int _size) //크기 늘려주기
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

	T* pTemp = new T[_size];


	//기존 공간에 있던 데이터를 새로 할당한 공간으로 복사해 준다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pTemp[i] = m_pData[i];
	}

	delete[] m_pData;

	m_pData = pTemp;

	m_iMaxCount = _size;

	std::cout << "MaxCount :" << m_iMaxCount << std::endl;


}
//{
//	return m_pInt[_idx];
//}


template<class T>
T& CArray<T>::operator[](int _idx) //연산자
{
	if (_idx < 0 || _idx >= m_iCount)
	{
		throw std::out_of_range("Index out of range");
	}

	return this->m_pData[_idx];
}

template<class T>
typename CArray<T>::iterator CArray<T>::begin()
{
	//컨테이너의 시작을 가리키는 iterator를 만들어 반환...
	

	return iterator();
}

template<class T>
void CArray<T>::OutPut() // 출력하기
{
	for (int i = 0; i < m_iCount; ++i)
	{
		std::cout << m_pData[i] << std::endl;
	}
}


template<class T>
void CArray<T>::Delete(int _size)
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
		pTemp[k++] = m_pData[i];
	}

	delete[] m_pData;

	m_pData = pTemp;


	--m_iCount;



	m_iMaxCount = m_iCount;

}


