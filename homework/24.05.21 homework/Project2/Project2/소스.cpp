#include <iostream>

int main()
{

	
	//1�� ����
	/*
	1-1.
	*
	**
	***
	****
	*****
	
	*/

	for (int i = 0; i < 5; ++i)
	{

		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << "\n";

	//2�� ����
	/*
	1-2.
	*****
	****
	***
	**
	*
	
	*/
	
	for (int i = 4; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	//for (int i = 0; i < 6; i++)
	//{

	//	for (int j = 5; j > i; j--)
	//	{
	//		std::cout << "*";
	//	}
	//	std::cout << "\n";
	//}

	//std::cout<< "\n";

	//3�� ����
	/* 1-3.
	    *
	   **
	  ***
	 ****
	*****
	*/
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 4; j > i; --j)
		{
			std::cout << " ";
		}
		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	//4�� ����
	/*
	1-4.
	*****
	 ****
  	  ***
	   **
	    *
	
	*/

	for (int i = 4; i >= 0; --i)
	{
		for (int j = 4; j > i; --j)
		{
			std::cout << " ";
		}

		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//5�� ����
	/*
	1-5.
		*
	   ***
	  *****
	 *******
	*/

	//���� 3 2 1 0 
	//���� 2�����߰� 

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j > i; --j)
		{
			std::cout << " ";
		}

		for (int j = 0; j < i * 2 + 1; ++j)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;

	//6�� ����
	/*
	1-6.
		 *
	    ***
	   *****
	  *******
	   *****
	    ***
	     *
	
	*/

	//i�� 0�϶� �� 6�϶� ���ƾ� �ȴ�.
	//i�� 1�϶� �� 5�϶� ���ƾ� �ȴ�.
	//i�� 2�϶� �� 4�϶� ���ƾ� �ȴ�.

	int iStar = 0;
	

	for (int i = 0; i < 7; ++i)
	{
		if (i > 3) //��������κ�
		{
			iStar = 6 - i;  //4-2 ,5-1 ,6-0
		}
		else
		{
			iStar = i; //0, 1, 2, 3 
		}

		
		for (int j = 3; j > iStar; --j)
		{
			std::cout << " ";
		}
		
		for (int j = 0; j < iStar * 2 + 1; ++j)
		{
			std::cout << "*";
		}

		std::cout << std::endl;

	}

	
	return 0;
}