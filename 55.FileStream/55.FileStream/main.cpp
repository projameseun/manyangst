#include <iostream>
#include <Windows.h>

int main()
{

	//인코딩방식
	//SetConsoleCP(65001);
	//SetConsoleOutputCP(65001); //윈도우 콘솔에서 출력 코드페이지(문자인코딩 방식)을 설정하는 함수
	
	//65001 : UTF - 8
	//949 : EUC-KR
	//437 : MS-DOS
	//9336 : GBK(중국어)

	//로케일을 설정해주는 함수 날짜,시간,숫자,인코딩,포맷 을 관리해줄수 있는 함수이다.
	setlocale(LC_ALL, "ko-kr");	

	/*
		스트림이란?
		실제 어원은 시냇물 흐르다라는 말에서 시작이 되었다.
		데이터의 흐름을 나타내는 용어다.
		결론적으로 데이터를 연속적으 흘려보내거나 받아오는 통로를 의미한다.
		
		ex)프로그램 <-------(스트림) 1)키보드 2)모니터 3(파일 4)... 5)네트워크 등 

		입력 스트림 : 외부 데이터가 프로그램에 들어오게 되는경우 
		출력 스트림 : 프로그램의 데이터를 외부로 내보내는 경우 

		c에서 쓰는 파일스트림 

		c언에서는 FILE구조체와 관련함수(fopen,fclose,fgets,fwirte등) 을 사용하여 파일을 처리한다.
		헤더파일은 stdio.h에 있습니다.
		
		
		c++ 에서 쓰는 표준 스트림
		std::cout , std::cin , std::cerr(에러출력)
		
		c++에서 쓰는 파일 스트림 
		std::ifstream -> 파일 입력 스트림(파일읽기)
		std::ofstream -> 파일 출력 스트림(파일쓰기)
		std::fstream -> 파일 입력 및 출력 스트림( 파일 읽기/쓰기 가능)
	
	*/
	
	//비쥬얼 스튜디오 버전에 따르 파일 구조체 내부 
	https://blog.naver.com/tipsware/221262052970
	
	//visual studio 2013까지는 FILE구조체가 

	//typedef struct _iobuf
	//{
	//	char*	_ptr;
	//	int		_cnt;
	//	char*	_base;
	//	int		_flag;
	//	int		_file;
	//	int		_charbuf;
	//	char*	_bufsiz;
	//	char*	_tmfname
	//}FILE;
	
	//2017변경
	//typedef struct _iobuf
	//{
	//	void* _Placeholder;
	//} FILE;

	/*
		이렇게 구조체의 내부가 변경된 이유는?
		구조체의 내부 구현 세부사항을 감추고 파일 입출력 기능을 사용자가 직접 다루지 못하도록 하기 위함
		이렇게 설계를 한 이유가 추상화와 호환성유지를 하기 위해서이다.

		FILE구조체의 실제구현은 운영체제와 라이브러리 버전 마다 다르다.
		내부를 void*로 감추면 개발자가 FILE내부에 직접 접근하거나 조작할수 없다.
		이는 추상화를 제공하고 사용자고 파일 스트림 동작원리를 몰라도 간단히 입출력을 수행할수 있게 해준다. 
		또한 내부 구조를 변경해도 외부코드와의 호환성이 유지된다.

		void* _Placeholder 로 정의되어있지만 실제 구현은 MSVC런타임 라이브러리 내부에 비공개로 존재하고 있다(사용자가 접근할수 없다)

		FILE* 는 레스토랑의 주문 번호표와 비슷하다
		사용자는 번호표(주소)를 기다리면, 주방(라이브러리 내부)에서 알아서 요리를 준비해준다고 보면 된다.
		내부과정(레시피,재료처리 등)은 손님에게 보이지 않는다 우린 결과만 받아들이면 된다.
		
	*/

	FILE* pFile = nullptr;	


	//_ACRTIMP errno_t __cdecl fopen_s(
	//	_Outptr_result_nullonfailure_ FILE * *_Stream,
	//	_In_z_                        char const* _FileName,
	//	_In_z_                        char const* _Mode
	//);
	//
	fopen_s(&pFile, "test.txt", "r");

	if (pFile == nullptr)
	{
		perror("Faild to Open File");
		return 0;
	}


	//출력
	char Buffer[256] = {};
	
	//_ACRTIMP char* __cdecl fgets(
	//	_Out_writes_z_(_MaxCount) char* _Buffer,
	//	_In_                      int   _MaxCount,
	//	_Inout_                   FILE * _Stream
	//);
	//fgets() 함수는 스트림에서 문자열을 받아서( MaxCount -1) 개의 문자를 입력 받을때 까지나, 개행 문자나 파일끝에 도달할때가지 입력을 받아서
	//C형식의 문자열로 저장한다.
	//개행문자는 fgets로 하여금 입력을 끝나게 하지만 이문자 역시 _Buffer에 저장된다.
	//NULL문자는 ㅈ장도적으로 마지막으로 입력받은 문자뒤에 붙는다.
	//fgets함수는 scanf함수와 달리 오직 개행문자의 의해서만 입력이 끝나기 때문에 띄어쓰기가 있는 문자열도 입력받을수 있다.
	//반면에 scanf함수의 경우 개행문자 뿐만 아니라 ' '와 '\t' 의 의해서도 입력이 끝나기때문에 띄어쓰기가 있는 문자열은 받을수 없다.
	
	
	//fseek file seek(찾다)
	//파일 포인터에의 위치를 변경하는데 사용
	//_ACRTIMP int __cdecl fseek(
	//	_Inout_ FILE * _Stream,		
	//	_In_    long  _Offset,	이동할 바이트수를 나타내며,양수이면 앞으로, 음수이면 뒤로 이동한다.
	//	_In_    int   _Origin	offset의 기준위치를 지정한다 
	//							SEEK_SET:파일 시작 기준으로 한다
	//);						SEEK_CUR :파일 포인터의 현재위치를 기준으로 한다
	//							SEEK_END : 파일 끝을 기준으로 한다 
	//fseek함수가 성공적으로 실행이 되면 0을 반환하고 실패하면 0이아닌 다른값을 반환한다.



	fseek(pFile, 0, SEEK_END);
	size_t iSize = ftell(pFile);	//파일 포인터의 현재위치를 반환하는 함수이다. 즉, 파일을 읽거나 쓸때 현재 파일에서 몇번째 바이트를 가리키고있는지 알이낼수 있다.
	fseek(pFile, 0, SEEK_SET);

	//fgets(Buffer, iSize, pFile);
	//std::cout << Buffer;
	//fgets(Buffer, iSize, pFile);
	//std::cout << Buffer;
	//fgets(Buffer, iSize, pFile);
	//std::cout << Buffer;


	//_ACRTIMP size_t __cdecl fread(
	//	_Out_writes_bytes_(_ElementSize * _ElementCount) void* _Buffer,
	//	_In_                                             size_t _ElementSize,		각 항목의크기(바이트단위)
	//	_In_                                             size_t _ElementCount,		읽은 갯수
	//	_Inout_                                          FILE * _Stream				스트림
	//);

	//바이너리 형식으로 뽑아내면 \n뿐만이아니라 \r도 존재한다는거 
	fread(Buffer, 1, iSize, pFile);
	Buffer[iSize] = '\0';
	

	std::cout << Buffer << std::endl;


	//========================파일 쓰기===================================

	
	//memset(Buffer, 0, iSize);	//0으로 싹다초기화
	
	const char* str = "안녕하세요 저는 책을 좋아합니다\n";

	fseek(pFile, -1, SEEK_END);

	char lastchar = fgetc(pFile);

	//만약에 문자열이 지금 라스트가 \n 또는 마지막이 아니라면 \n을 강제로 넣어준다
	//EOF end of file -1을 반환
	
	if (lastchar != '\n' && lastchar != EOF)
	{
		fseek(pFile, 0, SEEK_END);
		fputs("\n", pFile);
	}

	//fputs(str, pFile);
	
	//fputs,fprtinf는 데이터를 "출력 스트림을 보낸다" 
	//스트림이 콘솔이면 화면에 "출력"
	//스트림이 파일이면 "파일에 저장 되는 것이다"

	//출력의 의미
	//1.표준출력 : 화면(콘솔)
	//2.파일 : 저장장치
	//3.네트워크 소켓 :다른 컴퓨터와의 통신
	//즉, 출력이라는 단어는 단순히 화면에 보여주는 것 뿐만이 아니라, 데이터를 외부의 "전송"한다는 의미로 확장된다.
	
	//쓰기->데이터를 저장하는 작업으로 직접적으로 의미한다.
	//하지만 C에서 "쓰기"는 단순히 파일에 데이터를 저장하는것 뿐만 아니라, 출력 스트림을 통해 데이터를 전송하는 개념과도 같다.

	//결론적으로 "출력"과 "쓰기"는 개념적으로 매우 비슷하며, 둘 다 데이터를 "어디론가 보낸다" 는 뜻을 포함하고 있다
	//결론-->콘솔 화면에 출력한다, 파일에 데이터를 보낸다, 네트워크 데이터를 보낸다

	fprintf(pFile, "%s", "디발깻다다아아");


	//파일 닫기를 무조건 해줘야된다 .
	//이때 스트림의 모든 버퍼들을 비워준다(flush)
	//혹시나 fclose함수의 호출이 실패하더라도 인자로 전달된 스트림과 이에 해당하느 파일의 관계는 끊어진다.
	fclose(pFile);


	//새로운 파일을 생성한다
	FILE* pNewFile = nullptr;
	
	fopen_s(&pNewFile, "newFile.txt", "a+");

	if (pNewFile == nullptr)
	{
		return 1;
	}

	fputs("진짜 끝난다\n", pNewFile);

	fclose(pNewFile);


	return 0;
}