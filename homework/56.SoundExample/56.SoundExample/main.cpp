#include "Info.h"
#include "Music.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Music mic;

	mic.InitRecordName();
	
	mic.InitRecordPath(mic.GetRecordName());
	//���ڵ��� ����߰� 

	vector<LPCWSTR> rePath;

	//�뷡����
	while (true)
	{
		system("cls");

		std::cout << "1. �Ϲ� ���" << std::endl;
		std::cout << "2. ���� ���" << std::endl;
		std::cout << "3. ������" << std::endl;

		int iSelect = 0;

		std::cin >> iSelect;

		if (iSelect < 0 || iSelect >3)
		{
			std::cout << "������ �߸� �Ͽ����ϴ� �ٽ� �������ּ���" << std::endl;
			Sleep(500);
			continue;
		}

		if (iSelect == (int)MenuSelect::DefaultPlay)
		{
			//1.����������
			mic.MusicMenuPrint();

			//2.���ڵ��н��� �̿��ؼ� ������ Device
			for (int i = 0; i < mic.GetRecordName().size(); ++i)
			{
				rePath = mic.GetRecordPath();
				mic.InitMusiceDevic(rePath[i]);
			}
			
			

		}
		else if (iSelect == (int)MenuSelect::RandomPlay)
		{
			
		}
		else if (iSelect == (int)MenuSelect::EXIT)
		{
			std::cout << "�̿��� �ּż� �����մϴ�" << std::endl;
			Sleep(700);
			break;
		}

		//�뷡 ��� ��Ϲ�ȣ
		iSelect = 0;

		std::cin >> iSelect;

		if (iSelect < 1 || iSelect > 10)
		{
			std::cout << "������ �߸� �Ͽ����ϴ� �ٽ� �������ּ���" << std::endl;
			Sleep(500);
			continue;
		}

		//�뷡���� 
		mic.MusicUpdate(iSelect);
	}

	return 0;
}

