#include <iostream>


/*
���� 1.
���� for���� Ȱ���ؼ� �Ʒ� ������ ����Ѵ�.
1-1.
*
**
***
****
*****

1-2.
*****
****
***
**
*

1-3.
	*
   **
  ***
 ****
*****

1-4.
*****
 ****
  ***
   **
	*

1-5.
   *
  ***
 *****
*******

1-6.
   *
  ***
 *****
*******
 *****
  ***
   *
*/



int main()
{
	/*
		while �ַ� ���� ������ ������ ���� ����Ѵ�.
		������ ���鶧 �������� ������ ���� ����Ѵ�.
		while(���ǽ�) //���ǽ��� �����϶� ������ �ȴ�. , break�� ������ ���� �ȴ�.
		{

		}

		do while : ó�� �ѹ��� ������ ������ �ǰ� �� �Ŀ� ���ǽ��� üũ�Ͽ� false�� ����������.
		do
		{
			�ڵ�
		}while(���ǽ�);
		
	*/

	int iGameStart = 0;

	iGameStart = 1;

	/*while (iGameStart)
	{
		system("cls");
		std::cout << "���� ���� " << std::endl;

		for (int i = 0; i < 1000; ++i)
		{
			std::cout << i << std::endl;
		}

		iGameStart = 0;
		
	}*/

	int iNum = 1;

	do
	{
		iNum++;
		std::cout << "iNum = " << iNum <<std::endl;
		
	} while (iNum == 0);




	return 0;
}