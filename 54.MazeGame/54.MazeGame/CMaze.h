#pragma once
#include "GameInfo.h"

class CMaze
{
public:
	CMaze();
	~CMaze();

private:
	char	m_strName[64];
	char**	m_pBlock;
	char**	m_pBlocklOrigin;
	int		m_iWidth;
	int		m_iHeigth;

	//COORD	m_tStatrtPos;
	//COORD	m_tExitPos;

public:
	int GetWidth() const
	{
		return m_iWidth;
	}
	int GetHeigth() const
	{
		return m_iHeigth;
	}

	const char* GetName() const
	{
		return m_strName;
	}

public:
	bool Start(const char* pFileName);
	void Render(char* pBuffer);
	
};

