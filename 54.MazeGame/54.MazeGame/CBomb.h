#pragma once
#include "CObject.h"
class CBomb : public CObject
{
public:
	CBomb();
	~CBomb();

private:
	int				m_iPower;
	float			m_fBombTime;
	std::function<void(CBomb*)>		m_BombCallBack;	

	//void(CObject::* m_pFunc)(CBomb*); //Ÿ���� �μ��� �޴� ��� �Լ�������
	//CObject*		m_pObj;	//�ݹ� �Լ��� ȣ��� ��ü�� ������(�ּ�


public:
	virtual bool Start();
	virtual void Update(float _fDeltaTime);
	virtual void Render(char* _pBuffer);


public:
	//std::function<void(int)> funcName1 = Func;	//�Լ�����
	//std::function<void(int)> funcName2 = [](int a) {}; //�����Լ� 
	//std::function<void(int)> funcName3 = std::bind(�Լ����ּ�,����1,����2,); 

	//placeholder�ڸ�ǥ���� _1,_2,_3....����Ҽ� �ִµ� �� �ش��ȣ�� ������Ű�� �ʰڴٴ� �ǹ�
	//���ø��� ����Ͽ� Ư�� ��ü�� �ɹ��Լ��� �ݹ����� �����ϴ� �Լ�

	//1.�ݹ� �Լ��� ȣ��� ��ü�� ������(�ּ�), 2Ÿ���� �μ��� �޴� ��� �Լ�������
	//std::bind�� ��� �Լ������Ϳ� ��ü ������(�ּ�)�� �����Ͽ� ��� �Լ��� ȣ���Ҽ� �ִ� �Լ� ��ü�� �����Ҽ��� �ִ�.


	//pBomb->SetBombCallBack(this, &CPlayer::BombCallBack);

	//��ȯ��(Ŭ�����̸�::* �������̸�)(�Ű����� ���);
	//void(CObject::* m_pFunc)(CBomb*);
	template<typename T>
	void SetBombCallBack(T* _pObj, void(T::* _pFunc)(CBomb*))
	{
		
		m_BombCallBack = std::bind(_pFunc, _pObj, std::placeholders::_1);

		
		//m_pObj = _pObj;
		//m_pFunc = static_cast<void(CObject::*)(CBomb)>(_pFunc);

	}
};

