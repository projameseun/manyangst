#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)


using namespace std;

namespace Test
{
	void cout()
	{
		std::cout << "test cout" << std::endl;
	}
}

void MYEndl()
{
	std::printf("\n");
	std::fflush(stdout);
	
}


namespace MYStd
{
	class MyOStream
	{
	public:
		MyOStream& operator << (const int _idata)
		{
			printf("%d", _idata);
			return *this;
		}
		MyOStream& operator << (const float _idata)
		{
			printf("%.f", _idata);
			return *this;
		}
		MyOStream& operator << (const char* _pString)
		{
			printf("%s", _pString);
			return *this;
		}
		MyOStream& operator << (const std::string& _string)
		{
			printf("%s", _string.c_str());
			return *this;
		}

		MyOStream& operator <<(MyOStream&(*_func)(MyOStream&))
		{
			return _func(*this);
		}

		MyOStream& operator << (void(*_func)(void))
		{
			_func();
			return *this;
		}
	};

	MyOStream& endl(MyOStream& _ref)
	{
		std::printf("\n");
		std::fflush(stdout);
		return _ref;
	}

	class MyIStream
	{
	public:
		MyIStream& operator >> (int& _idata)
		{
			scanf_s("%d",&_idata);
			return *this;
		}

		MyIStream& operator >> (char& _cString)
		{
			scanf_s("%s", &_cString,25);
			return *this;
		}

		MyIStream& operator >> (char* _pString)
		{
			scanf_s("%s", &_pString, 25);
			return *this;
		}

		MyIStream& operator >> (float& _fdata)
		{
			scanf_s("%s", &_fdata, 25);
			return *this;
		}

		MyIStream& operator >> (std::string& _string)
		{
			char buffer[1024];
			scanf_s("%s", buffer, 1024);
			_string = buffer;
			return *this;
		}
	};

	MYStd::MyOStream cout;
	MYStd::MyIStream cin;
}




//class MYTest
//{
//public:
//	static void OutPut()
//	{
//		std::cout << "OutPut" << std::endl;
//	}
//};



int main()
{
	//std::cout << "test" <<  std::endl;

	//std::cout << 10 << std::endl;
	//
	//char c[25];

	//std::string str;

	//str = "¾È³çÇÏ¼¼¿ä";

	//MYStd::cout << 10;

	//MYStd::cout << str;\

	int a = 0;

	//std::cin >> a;

	//std::cout << a << std::endl;

	//MYStd::cin >> a;

	//MYStd::cout << a;

	std::string str;
	MYStd::cin >> str;

	MYStd::cout << str;

	std::cout << std::endl;

	 MYStd::cout << str << MYEndl;

	 MYStd::cout << 3 << " " << 10 << " " << str << MYEndl;

	 


 	return 0;
}