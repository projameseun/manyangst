#pragma once
#include "GameInfo.h"

class CObject
{
public:
	CObject();
	virtual ~CObject();
protected:
	COORD	 m_tPos;		//ObjectÀ§Ä¡
	bool	 m_bAticve;

public:
	bool GetActive() const
	{
		return m_bAticve;
	}

	void Destroy()
	{
		m_bAticve = false;
	}

	void SetPos(const COORD& tPos)
	{
		m_tPos = tPos;
	}

	COORD GetPos() const
	{
		return m_tPos;
	}

public:
	virtual bool Start();
	virtual void Update(float _fDeltaTime);
	virtual void Render(char* _pBuffer);
};

