#pragma once
#include <assert.h>

template <class T>
class CVector
{
private:
		T*				m_pData;
		unsigned int	m_iCount;
		unsigned int	m_iMaxCount;

public:
	CVector();
	~CVector();
	
	//fun
public:
	void push_back(const T& _data);
	void resize(const int _size);
	void Delete(int _idx);

	//Get,Set
public:
	int size() const
	{
		return m_iCount;
	}

	void clear()
	{
		m_iCount = 0;
	}


	
	//operator
public:
	T& operator[](int _idx);

public:
	//iter
	class iterator;
	iterator begin();
	iterator end();
	iterator earse(iterator& _riter);

	//iter
public:
	class iterator
	{
	private:
		CVector*	m_pVector;		//ieterator가 가리키는 가변배열주소
		T*			m_pData;		//데이터 시작주소
		int			m_idx;			//인덱스
		bool		m_bValid;		//유효검사

	public:
		iterator() :
			m_pVector(nullptr),
			m_pData(nullptr),
			m_idx(-1),		//end() -1
			m_bValid(false)
		{

		}

		iterator(CVector* _pVector, T* _data, int _idx) :
			m_pVector(_pVector),
			m_pData(_data),
			m_idx(_idx),		//end() -1
			m_bValid(false)
		{
			if (_pVector != nullptr && _idx >= 0)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{

		}

		friend class CVector;

		//iteroper
	public:
		T& operator *()
		{
			if (m_pVector->m_pData != m_pData || m_idx == -1 || m_bValid == false)
			{
				assert(nullptr);
			}

			return m_pData[m_idx];
		}

		//전위
		iterator& operator++()
		{
			if (m_pVector->m_pData != m_pData || m_idx == -1 || m_bValid == false)
			{
				assert(nullptr);
			}

			//마지막데이터를 가리키는경우
			if (m_pVector->size() - 1 == m_idx)
			{
				m_idx = -1;
			}
			else
			{
				++m_idx;
			}

			return *this;
		}

		iterator& operator++(int)
		{
			

			iterator copyiter = *this;
			++(*this);

			return copyiter;
		}

		//전위
		iterator& operator--()
		{
			if (m_pVector->m_pData != m_pData || m_idx == 0 || m_bValid == false)
			{
				assert(nullptr);
			}

			--m_idx;

			return *this;
		}

		iterator& operator--(int)
		{


			iterator copyiter = *this;
			--(*this);

			return copyiter;
		}

		bool operator ==(const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_idx == _otheriter.m_idx)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator !=(const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_idx == _otheriter.m_idx)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		
	};
	

};

template<class T>
 CVector<T>::CVector() :
	 m_pData(nullptr),
	 m_iCount(0),
	 m_iMaxCount(2)
{
	 m_pData = new T[2];
}

template<class T>
CVector<T>::~CVector()
{
	if (m_pData != nullptr)
	{
		delete[] m_pData;
	}
}


template<class T>
inline void CVector<T>::push_back(const T& _data)
{
	//exception
	if (m_iCount >= m_iMaxCount)
	{
		//재할당
		//std::cout << "재할당 해야 됩니다" << std::endl;
		resize(m_iMaxCount * 2);
		
	}

	m_pData[m_iCount++] = _data;

}

template<class T>
void CVector<T>::resize(const int _size)
{
	//exception
	if (m_iMaxCount >= _size)
	{
		throw std::runtime_error("할당할 크기가 MaxCount보다 같거나 작습니다 ");

	}

	T* pNewData = new T[_size];

	//데이터들을 새로 할당한 공간으로 복사해준다.

	for (int i = 0; i < size(); ++i)
	{
		pNewData[i] = m_pData[i];
	}
	
	//delete[] m_pData;

	m_pData = pNewData;


	m_iMaxCount = _size;

	

}

template<class T>
 void CVector<T>::Delete(int _idx)
{
	 if (_idx < 0 || _idx >= m_iCount)
	 {
		 assert(nullptr);
	 }

	 for (int i = _idx; i < size() - 1; ++i)
	 {
		 m_pData[i] = m_pData[i + 1];
	 }

	 m_iCount--;
}

template<class T>
 T& CVector<T>::operator[](int _idx)
{
	 if (_idx < 0 || _idx >= m_iCount)
	 {
		 assert(nullptr);
	 }

	 return m_pData[_idx];
}

 template<class T>
 inline typename CVector<T>::iterator CVector<T>::begin()
 {
	 if (m_iCount == 0)
	 {
		 return iterator(this,m_pData,-1);	
	 }

	 return iterator(this, m_pData, 0);
	
 }

 template<class T>
 inline typename CVector<T>::iterator CVector<T>::end()
 {
	 return iterator(this,m_pData,-1);
 }

 template<class T>
 typename CVector<T>::iterator CVector<T>::earse(iterator& _riter)
 {
	 if (_riter.m_pVector != this || end() == _riter || _riter.m_idx >= m_iCount)
	 {
		 assert(nullptr);
	  }

	 //삭제
	 int iLoop = m_iCount - (_riter.m_idx + 1);

	 for (int i = 0; i < iLoop; ++i)
	 {
		 m_pData[i + _riter.m_idx] = m_pData[i + _riter.m_idx + 1];
	 }

	 //
	 _riter.m_bValid = false;

	 --m_iCount;

	 return iterator(this,m_pData,_riter.m_idx);
 }
