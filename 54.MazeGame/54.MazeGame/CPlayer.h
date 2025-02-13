#pragma once
#include "CObject.h"
class CPlayer :public CObject
{
public:
	CPlayer();
	~CPlayer();	

private:
	float	m_fSpeed;
	float	m_fX;
	float	m_fY;
	//��ź��ġ�Ѵٸ� ��źī��Ʈ,��ź���Ŀ�

public:
	void clear()
	{
		m_fX = 0.f;
		m_fY = 0.f;
	}
public:
	virtual bool Start();
	virtual void Update(float _fDeltaTime);
	virtual void Render(char* _pBuffer);
};

