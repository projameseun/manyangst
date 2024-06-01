#include <iostream>
#include <time.h>

/*
	1~9»çÀÌÀÇ ·£´øÇÔ ¼ýÀÚ 3°³¸¦ Áßº¹ ¾øÀÌ ¾ò¾î¿Â´Ù.
	¸¸¾à¿¡ ·£´øÇÔ°Ô ¾ò¾î¿Â ¼ýÀÚ°¡ 8,3,9 ÀÏ °æ¿ì

	±×ÈÄ¿¡ ¹«ÇÑÀ¸·Î ¹Ýº¹ÇÑ´Ù.
	»ç¿ëÀÚ´Â 3°³ÀÇ ¼ýÀÚ¸¦ ÀÔ·ÂÇÕ´Ï´Ù.
	1 , 2, 4¸¦ ÀÔ·ÂÇß´Ù¸é Áßº¹µÇ´Â ¼ýÀÚ°¡ ¾Æ¿¹¾øÀ¸¹Ç·Î outÀ» Ãâ·ÂÇÑ´Ù
	8 , 4, 5¸¦ ÀÔ·ÂÇß´Ù¸é 8Àº ¼ýÀÚµµ °°Àº°Ô ÀÖ´Âµ¥ ÀÚ¸®¤¿±îÁö °°À¸¹Ç·Î strike·Î Ã³¸®ÇÑ´Ù
	³ª¸ÓÁö´Â ¾øÀ¸¹Ç·Î 1strike 0ballÀ» Ãâ·ÂÇÑ´Ù
	ÀÌ·±½ÄÀ¸·Î ¼ýÀÚ°¡ °°Àºµ¥ ÀÚ¸®±îÁö °°´Ù¸é strikeÃß°¡ ÀÚ¸®°¡ ´Ù¸£¸é ball·Î Ãß°¡ÇØ¼­
	Ç¥½ÃÇØÁØ´Ù .
	¸ðµç ¼ýÀÚ¸¦ ÀÚ¸®±îÁö ¸Â­Ÿ´Ù¸é °ÔÀÓÀÌ Á¾·á µÈ´Ù.
*/

int main()
{

	srand(static_cast<unsigned int>(time(NULL)));


	int iNumber[9] = {};

	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	int iTemp, idx1, idx2 = 0;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
		
	}

	while (true)
	{
	
		std::cout << "*\t*\t*" << std::endl;
		std::cout << "¼ýÀÚ 3°³¸¦ ÀÔ·Â ÇÏ¼¼¿ä (0:Á¾·á) :";

		int iInput[3] = {};

		std::cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
		{
			break;
		}

		int iStrike = 0, iBall = 0;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
					{
						++iStrike;
					}
					else
					{
						++iBall;
					}
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			std::cout << "¼ýÀÚ¸¦ ¸ðµÎ ¸ÂÃè½À´Ï´Ù " << std::endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
		{
			std::cout << "Out !! " << std::endl;
		}

		else
		{
			std::cout << "Strike : " << iStrike << "Ball : " << iBall << std::endl;
		}
	}
	


	return 0;
}