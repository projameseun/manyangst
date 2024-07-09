#include <iostream>
#include <assert.h>

unsigned int GetLength(const wchar_t* pwChar)
{
	int i = 0;

	/*while (true)
	{
		wchar_t c = *(pwChar + i);
		
		if ('\0' == c)
		{
			break;
		}

		++i;
	}*/

	while ('\0' != pwChar[i])
	{
		++i;
	}

	return i;
}

size_t GetLength2(const wchar_t* pwChar)
{
	size_t len = 0;

	while (*pwChar++)
	{
		
		len++;

	}

	return len;
}



void StrCat(wchar_t* _Destination, size_t _BufferSize, const wchar_t* _Source)
{
	size_t iDestSize = GetLength(_Destination);
	size_t iSourceSize = GetLength(_Source);



	if (_BufferSize < iDestSize + iSourceSize + 1)	//NULL
	{
		assert(nullptr);
	}

	//���ڿ� ���̱� 
	//1.�������� ���ڿ��� ���� Ȯ��(���� �ڿ� ���ڿ��� ���ϰŴϱ�)
	//2.�ҽ���ġ���ڿ��� ������ ���� �ٿ��ش�.

	for (int i = 0; i < iSourceSize + 1; ++i)
	{
		_Destination[iDestSize + i] = _Source[i];
	}
}

char* StrCat2(char* dest, const char* src)
{
	char* result = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = '\0';

	return result;
}

int wcsCmp(const wchar_t* string1, const wchar_t* string2)
{
	//���ڿ��� ������ 0 
	//string1�� string2 ���� ������� -1
	//string�� string2���� ū��� +1

	size_t strlen = GetLength(string1);
	size_t strlen2 = GetLength(string2);


	size_t iLoop = strlen;
	size_t iReturn = 0;

	if (strlen < strlen2)
	{
		iLoop = strlen;
		iReturn = -1;
	}

	else if(strlen > strlen2)
	{
		iLoop = strlen2;
		iReturn = +1;
	}

	for (int i = 0; i < iLoop; ++i)
	{
		if (string1[i] < string2[i])
		{
			return -1;
		}
		else if (string1[i] > string2[i])
		{
			return 1;
		}
	}


	return iReturn;
	
	
}

int wcsCmp2(const wchar_t* string1, const wchar_t* string2)
{

	while (*string1 || *string2) //���߿� �ϳ��� null�̾ƴ϶�� �ݺ�
	{
		if (*string1 != *string2)	//�ٸ����
		{
			return(*string1 > *string2) ? 1 : -1;
		}

		string1++;
		string2++;
	}

	//�� ���ڿ��� �������
	return 0;
}


int main()
{
	//c++������ ���ڿ��� ������ �迭�� ǥ���̵˴ϴ�.
	

	wchar_t stwChar[25] = L"abcdef";	//{a,b,c,d,e,f};
	

	//���ڿ� ���̸� ��ȯ���ִ� �Լ��� �츮�� ����������
	{
		wchar_t stName[25] = L"World!gg";
		//size_t
	
		size_t Len = GetLength(stName);
		size_t Len2 = GetLength(stName);
		std::cout << Len << std::endl;

	}

	//���ڿ� �̾���̱�
	{
		wchar_t stName[100] = L"Hellow";
		wchar_t stName2[100] = L"Word";

		/*_Inout_updates_z_(_SizeInWords) wchar_t* _Destination,
			_In_ rsize_t _SizeInWords,
			_In_z_ wchar_t const* _Source*/
	/*	wcscat_s(stName, 100, stName2);

		size_t Len = GetLength(stName);

		for (int i = 0; i < Len; ++i)
		{
			std::wcout <<  stName[i];
		}*/

		std::wcout << std::endl;
		StrCat(stName, 100, stName2);

		std::wcout << stName << std::endl;

		char cName[100] = "�ȳ��ϼ���";
		char cName2[100] = " �������Դϴ�";

		StrCat2(cName, cName2);

		std::cout << cName << std::endl;
	
	}

	{
		//���ڿ��� ���� ������ 0 
		// cName�� cName2���� ������� ���� -1
		// cName�� cName2���� ū��� ��� +1
		//��������� �쿭�� ������ ������ ���+1  ������ ������ ���� -1
		char cName[100] = "ff";
		char cName2[100] = "fff";
		int Test = strcmp(cName, cName2);

		

	}

	{
		int iRet = wcscmp(L"abc", L"abcd");

		int iResult = wcsCmp(L"abc", L"abcd");

		
		
	}

	

	return 0;
}
