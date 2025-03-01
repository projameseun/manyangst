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
	int		m_iHeight;

	COORD	m_tStatrtPos;
	COORD	m_tExitPos;

public:
	int GetWidth() const
	{
		return m_iWidth;
	}
	int GetHeigth() const
	{
		return m_iHeight;
	}

	const char* GetName() const
	{
		return m_strName;
	}

	COORD GetStartPos() const
	{
		return m_tStatrtPos;
	}

	COORD GetExitPos() const
	{
		return m_tExitPos;
	}

	BLOCK GetBlock(const COORD& _pos) const
	{
		return (BLOCK)m_pBlock[_pos.Y][_pos.X];
	}

	void SetBlock(const COORD& _pos, BLOCK _block)
	{
		m_pBlock[_pos.Y][_pos.X] = (char)_block;
	}


	void clear()
	{

	}

public:
	bool Start(const char* pFileName);
	void Render(char* pBuffer);
	
};

