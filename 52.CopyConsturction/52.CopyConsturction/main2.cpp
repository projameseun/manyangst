#include <iostream>
#include <string>


class Man
{
public:
	char* m_Name;
	int m_iAge;

public:
	Man& operator = (const Man& _other)
	{
		if (this != &_other)
		{
			if (m_Name)
			{
				delete[](m_Name);
				m_Name = nullptr;
			}


			m_iAge = _other.m_iAge;

			//�� �޸� �Ҵ�
			if (_other.m_Name)
			{
				//c�����
			/*	m_Name = (char*)malloc(25);
				strcpy_s(m_Name, 25, _other.m_Name);*/
				

				size_t iLength = strnlen_s(_other.m_Name, 25);

				//c++���
				m_Name = new char[iLength + 1];
				strcpy_s(m_Name, iLength + 1, _other.m_Name);

			}
			else
			{
				m_Name = nullptr;
			}

		}
		return *this;
	}

public:
	void Destroy()
	{
		if (m_Name != nullptr)
		{
			delete[](m_Name);
			m_Name = nullptr;
		}
	}

public:
	~Man()
	{
		Destroy();
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	class Man Manyang;
	class Man James;

	Manyang.m_Name = (char*)malloc(25);
	James.m_Name = (char*)malloc(25);

	size_t iManLength = strnlen_s(Manyang.m_Name, 25);
	size_t iJamesLength = strnlen_s(James.m_Name, 25);

	strcpy_s(Manyang.m_Name, iManLength, "Manyang");
	Manyang.m_iAge = 25;

	strcpy_s(James.m_Name, iJamesLength, "James");
	James.m_iAge = 37;

	 Manyang = James;	//��������

	//strcpy_s(James.m_Name, 25, Manyang.m_Name);	
	//���ڿ��� �����ѰŴ� �� �޸𸮸�  �Ҵ��Ѱ� �ƴ϶�°�
	//�ش� NAME�� �ٸ� �޸𸮸� ����Ű�� �Ǿ� free������ ������ ���� �ʴ´�.
	//��������� ��ü�� ���ο� ���纻�� �����Ѵ� 
	//strcpy_s�� ���ڿ��� �����Ҷ� ���޸𸮸� �Ҵ����� �����Ƿ� �������簡 �ƴϴ�.

	 //HEAP CORRUPTION DETECTED 
	 // ������ ������malloc�̳� new�� �Ҵ��� �޸��� �������� �� ū ������ �����ϰ��� �߱� �����̴�.
		
	 iManLength = 0;

	 iManLength = strnlen_s(Manyang.m_Name, 25);

	strcpy_s(Manyang.m_Name, iManLength, "tEST");

	std::cout << Manyang.m_Name << " " << Manyang.m_iAge << std::endl;
	std::cout << James.m_Name << " " << James.m_iAge << std::endl;



	
	return 0;

}