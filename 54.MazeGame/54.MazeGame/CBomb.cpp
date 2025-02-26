#include "CBomb.h"

CBomb::CBomb() : m_iPower(1), m_fBombTime(3.f)	
{
}

CBomb::~CBomb()
{
}

bool CBomb::Start()
{
	return true;
}

void CBomb::Update(float _fDeltaTime)
{
	//∆¯≈∫¿Ã≈Õ¡≥¿ª∂ß
	if (m_BombCallBack)
	{
		m_BombCallBack(this);

	}

}

void CBomb::Render(char* _pBuffer)
{
}
