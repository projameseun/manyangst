#include <iostream>



class Man
{
public:
	char* m_Name;
	int m_iAge;
};

int main()
{
	class Man Manyang;
	class Man James;

	Manyang.m_Name = (char*)malloc(25);
	James.m_Name = (char*)malloc(25);

	
	strcpy_s(Manyang.m_Name, 25, "Manyang");
	Manyang.m_iAge = 25;

	strcpy_s(James.m_Name, 25, "James");
	James.m_iAge = 37;

	//Manyang = James;	//��������

	strcpy_s(James.m_Name, 25, Manyang.m_Name);	
	//���ڿ��� �����ѰŴ� �� �޸𸮸�  �Ҵ��Ѱ� �ƴ϶�°�
	//�ش� NAME�� �ٸ� �޸𸮸� ����Ű�� �Ǿ� free������ ������ ���� �ʴ´�.
	//��������� ��ü�� ���ο� ���纻�� �����Ѵ� 
	//strcpy_s�� ���ڿ��� �����Ҷ� ���޸𸮸� �Ҵ����� �����Ƿ� �������簡 �ƴϴ�.


	strcpy_s(Manyang.m_Name, 25, "tEST");

	std::cout << Manyang.m_Name << " " << Manyang.m_iAge << std::endl;
	std::cout << James.m_Name << " " << James.m_iAge << std::endl;


	if (Manyang.m_Name != nullptr)
	{
		free(Manyang.m_Name);
		Manyang.m_Name = nullptr;
	}
	if (James.m_Name != nullptr)
	{
		free(James.m_Name);
		James.m_Name = nullptr;
	}

	
	
	
	return 0;

}