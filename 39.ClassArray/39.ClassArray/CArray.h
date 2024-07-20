#pragma once
class CArray
{
private:
	int*	m_pInt;
	int		m_iCount;
	int		m_iMaxCount;

public:
	int GetCount()
	{
		return m_iCount;
	}

	int GetMaxCount()
	{
		return m_iMaxCount;
	}

	int* GetpInt()
	{
		return m_pInt;
	}

public:
	CArray();
	~CArray();

public:
	void push_back(int _data);
	void resize(int _size);
	void OutPut();
	void Delete(int _size);

public:
	//int operator[] (int _idx);
	int& operator[] (int _idx);
	
};

