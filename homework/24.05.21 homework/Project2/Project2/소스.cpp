#include <iostream>

int main()
{

	
	//1번 문제
	/*
	1-1.
	*
	**
	***
	****
	*****
	
	*/

	for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}

	std::cout << "\n";

	//2번 문제
	/*
	1-2.
	*****
	****
	***
	**
	*
	
	*/

	for (int i = 0; i < 6; i++)
	{

		for (int j = 5; j > i; j--)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}

	std::cout<< "\n";

	//3번 문제
	/* 1-3.
	    *
	   **
	  ***
	 ****
	*****
	*/
	for (int i = 0; i < 6; i++)
	{
		std::cout << " ";
		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		
		}
		std::cout << "\n";
	}

	//4번 문제
	/*
	1-4.
	*****
	 ****
  	  ***
	   **
	    *
	
	*/

	for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
		std::cout << " ";
	}

	//5번 문제
	/*
	1-5.
		*
	   ***
	  *****
	 *******
	*/

	/*for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}*/

	//6번 문제
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

	/*for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}*/
	return 0;
}