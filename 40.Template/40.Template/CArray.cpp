//#include "CArray.h"
//#include <assert.h>
//#include <iostream>
//
//CArray::CArray()
//	: m_pData(nullptr),
//	m_iCount(0),
//	m_iMaxCount(2) //maxsize ����
//{
//	m_pData = new int[2];
//}
//
//CArray::~CArray()
//{
//
//	if (m_pData != nullptr)
//	{
//		delete[] m_pData;
//		m_pData = nullptr;
//	}
//}
//
//void CArray::push_back(int _data)
//{
//	//����ó��
//	if (m_iMaxCount <= m_iCount) //size�� maxsize���� Ŀ���� �� resize ȣ��
//	{
//		//���Ҵ�
//		resize(m_iMaxCount * 2);
//	}
//
//	m_pData[m_iCount++] = _data;
//
//
//}
//
//void CArray::resize(int _size) //ũ�� �÷��ֱ�
//{
//	//m_iMaxCount = 10;
//	//����ó�� 
//	if (m_iMaxCount >= _size)
//	{
//		//std::cout << "�Ҵ��� ũ�Ⱑ MaxCount���� ���ų� �۽��ϴ�" << std::endl;
//		//assert(nullptr);
//		throw std::runtime_error("�Ҵ��� ũ�Ⱑ MaxCount���� ���ų� �۽��ϴ�");
//
//		//
//
//	}
//
//	int* pTemp = new int[_size];
//
//
//	//���� ������ �ִ� �����͸� ���� �Ҵ��� �������� ������ �ش�.
//	for (int i = 0; i < m_iCount; ++i)
//	{
//		pTemp[i] = m_pData[i];
//	}
//
//	delete[] m_pData;
//
//	m_pData = pTemp;
//
//	m_iMaxCount = _size;
//
//	std::cout << "MaxCount :" << m_iMaxCount << std::endl;
//
//
//}
////{
////	return m_pInt[_idx];
////}
//
//int& CArray::operator[](int _idx) //������
//{
//	if (_idx < 0 || _idx >= m_iCount)
//	{
//		throw std::out_of_range("Index out of range");
//	}
//
//	return m_pData[_idx];
//}
//
//void CArray::OutPut() // ����ϱ�
//{
//	for (int i = 0; i < m_iCount; ++i)
//	{
//		std::cout << m_pData[i] << std::endl;
//	}
//}
//
//void CArray::Delete(int _size)
//{
//	if (_size < 0 || _size >= m_iCount) {
//		/*	std::cout << "��ȿ���� ����" << std::endl;
//			return;*/
//
//		throw std::out_of_range("Index out of Range");
//	}
//
//	int* pTemp = new int[m_iCount - 1];
//
//	int k = 0;
//
//	/*for (int i = _size; i < m_iCount - 1; ++i) {
//		m_pInt[i] = m_pInt[i + 1];
//	}*/
//
//	for (int i = 0; i < m_iCount; ++i)
//	{
//		if (i == _size)continue;
//		pTemp[k++] = m_pData[i];
//	}
//
//	delete[] m_pData;
//
//	m_pData = pTemp;
//
//
//	--m_iCount;
//
//
//
//	m_iMaxCount = m_iCount;
//
//}
