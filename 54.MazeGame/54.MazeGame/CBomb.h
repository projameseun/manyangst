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

	//void(CObject::* m_pFunc)(CBomb*); //타입의 인수를 받는 멤버 함수포인터
	//CObject*		m_pObj;	//콜백 함수가 호출될 객체의 포인터(주소


public:
	virtual bool Start();
	virtual void Update(float _fDeltaTime);
	virtual void Render(char* _pBuffer);


public:
	//std::function<void(int)> funcName1 = Func;	//함수대입
	//std::function<void(int)> funcName2 = [](int a) {}; //람다함수 
	//std::function<void(int)> funcName3 = std::bind(함수의주소,인자1,인자2,); 

	//placeholder자리표시자 _1,_2,_3....사용할수 있는데 그 해당번호를 고정시키지 않겠다는 의미
	//템플릿을 사용하여 특정 객체의 맴버함수를 콜백으로 설정하는 함수

	//1.콜백 함수가 호출될 객체의 포인터(주소), 2타입의 인수를 받는 멤버 함수포인터
	//std::bind는 멤버 함수포인터와 객체 포인터(주소)를 결합하여 멤버 함수를 호출할수 있는 함수 객체를 생성할수도 있다.


	//pBomb->SetBombCallBack(this, &CPlayer::BombCallBack);

	//반환형(클래스이름::* 포인터이름)(매개변수 목록);
	//void(CObject::* m_pFunc)(CBomb*);
	template<typename T>
	void SetBombCallBack(T* _pObj, void(T::* _pFunc)(CBomb*))
	{
		
		m_BombCallBack = std::bind(_pFunc, _pObj, std::placeholders::_1);

		
		//m_pObj = _pObj;
		//m_pFunc = static_cast<void(CObject::*)(CBomb)>(_pFunc);

	}
};

