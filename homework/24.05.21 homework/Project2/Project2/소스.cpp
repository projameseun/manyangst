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

	for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < i; j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
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

	for (int i = 0; i < 6; i++)
	{

		for (int j = 5; j > i; j--)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}

	std::cout<< "\n";

	//3�� ����
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

	//4�� ����
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

	//5�� ����
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