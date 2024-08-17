#pragma once

#include <assert.h>
#include <iostream>


template<class T>
class CArray
{
private:
	T* m_pData;
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

	class iterator;	//���漱��
	iterator begin();
	iterator end();


public:
	//�̳�Ŭ����
	//�ݺ��� 
	class iterator
	{
	private:
		CArray* m_pArr;			//iterator�� ����ų �����͸� �����ϴ� �����迭 �ּ�
		T* m_pData;		//������ �����ּ�
		int	m_iIdx;			//����Ű�� �ε���

	public:
		iterator() :
			m_pArr(nullptr),
			m_pData(nullptr),
			m_iIdx(-1)
		{

		}
		iterator(CArray* _pArr, T* _data, int _idx) :
			m_pArr(_pArr),
			m_pData(_data),
			m_iIdx(_idx)
		{

		}
		~iterator()
		{

		}

	public:
		//�� itator�� �˰��ִ� �ּҿ�, vector�� �˰� �ִ� �ּҰ� �޶������(������ Ȯ���ϰ� �ּҰ� �޶������)
		//iteartor �� end iterator�ϰ��..
		T& operator *()
		{
			if (m_pData != m_pArr->m_pData || m_iIdx == -1)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		//����
		iterator& operator ++()
		{
			//
			if (m_pData != m_pArr->m_pData || m_iIdx == -1)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}

			//iterator �� ������ �����͸� ��Ű���°�� 
			//end iterator�� �Ǵ°��
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		//����
		iterator operator ++(int)
		{
			//�ӽð�ü
			//��������ڰ� ȣ��ȰŴ�
			//�ڵ����� ���������...
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;

		}


		//-- ,-- ���� ����
		iterator& operator --()
		{
			if (m_pData != m_pArr->m_pData || m_iIdx == -1)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}

			if (m_pArr->size() - 1 == this->m_iIdx)
			{
				this->m_iIdx = -1;
			}
			else
			{
				--(m_iIdx);
			}
			return *this;
		}

		iterator operator --(int)
		{
			//�ӽð�ü
			//��������ڰ� ȣ��ȰŴ�
			//�ڵ����� ���������...
			iterator copy_iter = *this;

			--(*this);

			return copy_iter;

		};
	};
};


#pragma region vector
//vector

template<class T>
CArray<T>::CArray() :
	m_pData(nullptr),
	m_iCount(0),
	m_iMaxCount(2) //maxsize ����
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
	//����ó��
	if (m_iMaxCount <= m_iCount) //size�� maxsize���� Ŀ���� �� resize ȣ��
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}

	m_pData[m_iCount++] = _data;
}

template<typename T>
void CArray<T>::resize(int _size) //ũ�� �÷��ֱ�
{
	//m_iMaxCount = 10;
	//����ó�� 
	if (m_iMaxCount >= _size)
	{
		//std::cout << "�Ҵ��� ũ�Ⱑ MaxCount���� ���ų� �۽��ϴ�" << std::endl;
		//assert(nullptr);
		throw std::runtime_error("�Ҵ��� ũ�Ⱑ MaxCount���� ���ų� �۽��ϴ�");

		//

	}

	T* pTemp = new T[_size];


	//���� ������ �ִ� �����͸� ���� �Ҵ��� �������� ������ �ش�.
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
T& CArray<T>::operator[](int _idx) //������
{
	if (_idx < 0 || _idx >= m_iCount)
	{
		throw std::out_of_range("Index out of range");
	}

	return this->m_pData[_idx];
}


template<class T>
void CArray<T>::OutPut() // ����ϱ�
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
		/*	std::cout << "��ȿ���� ����" << std::endl;
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

//vector

#pragma endregion



//Iterator
template<class T>
typename CArray<T>::iterator CArray<T>::begin()
{
	//�����̳��� ������ ����Ű�� iterator�� ����� ��ȯ...

	if (m_iCount == 0)
	{
		return iterator(this, m_pData, -1);
	}

	//�ӽð�ü
	return iterator(this, m_pData, 0);



}


template<class T>
typename CArray<T>::iterator CArray<T>::end()
{


	return iterator(this, m_pData, -1);

}



//Iterator