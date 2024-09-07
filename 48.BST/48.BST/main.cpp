#include <iostream>
#include <set>
#include <string>
#include <map>

#include "CBST.h"

using std::string;
using std::wstring;
using std::endl;

enum class Gender
{
    MAN = 1,
    WOMAN = 2,

};

class CStdInfo
{
public:
    wstring              m_stName;
    unsigned char        m_Age;
    unsigned char        m_Gender;



public:
    CStdInfo() :
        m_stName{},
        m_Age(0),
        m_Gender(0)
    {

    }

    CStdInfo(const wstring& _pName, unsigned char _age, unsigned char _gender) :
        m_stName(_pName),
        m_Age(_age),
        m_Gender(_gender)
    {
        //wcscpy_s(m_stName, 25, _pName);
    }

};

class MyClass
{

};



int main()
{

    ////��������
   _wsetlocale(LC_ALL, L"korean");
   
    //map����...

   //std::set<int> setInt;

   //setInt.insert(100);
   //setInt.insert(50);
   //setInt.insert(150);

    
   
    //std::map<const wchar_t, CStdInfo> mapData;

    //CStdInfo info(L"�ڸ���", 20, (char)Gender::MAN);
    //CStdInfo info2(L"��ȿ��", 25, (char)Gender::WOMAN);


    //mapData.insert(std::make_pair(L"�ڸ���", info));
    //mapData.insert(std::make_pair(L"��ȿ��", info2));

    //std::map<const wchar_t, CStdInfo>::iterator mapiter;

    //wchar_t stName[25] = L"��ȿ��";    //�ּҰ� �ƿ��ٸ��Ű�

    //const wchar_t* pStr = L"�ڸ���";    //�ּҰ� ���Ƽ� ...

    //mapiter = mapData.find(pStr);

    ////��������
    //_wsetlocale(LC_ALL, L"korean");


    //if (mapiter == mapData.end())
    //{
    //    std::wcout << L"�ƹ��� ã�� ���߽��ϴ�" << std::endl;
    //}
    //else
    //{
    //    std::wcout << L"�̸� : " << mapiter->second.m_stName << std::endl;
    //    std::wcout << L"���� : " << mapiter->second.m_Age << std::endl;
    //    std::wcout << L"���� : ";
    //    if ((char)Gender::MAN == mapiter->second.m_Gender)
    //    {
    //        std::wcout << L"����" << std::endl;
    //    }
    //    else if ((char)Gender::WOMAN == mapiter->second.m_Gender)
    //    {
    //        std::wcout << L"����" << std::endl;
    //    }

    //    else
    //    {
    //        std::wcout << L"�ƹ��͵� ã�� ���߽��ϴ�." << std::endl;
    //    }

    //}

    //������ ���� ���ڿ��� ã�Ƽ� ã�Ƴ´ٰ� ��������.
    //�ּҰ��� ���ؼ� ���°��̴�. �ּ��� ���� ã���Ŵ�.
    //�츮�� ���ϴ� ���ڿ��� ã�Ƽ� �����÷����ϸ� string�Լ��� ����ؾ� �ȴ�.

    system("cls");
    
#pragma region MapBasic
    {
        std::map<wstring, CStdInfo> mapData;

        CStdInfo info(L"����", 20, (char)Gender::MAN);
        CStdInfo info2(L"�質��", 25, (char)Gender::WOMAN);

        mapData.insert(std::make_pair(L"����", info));
        mapData.insert(std::make_pair(L"�質��", info2));

        wstring stTest;

        stTest = L"�質��";

        std::map<wstring, CStdInfo>::iterator mapiter;

        mapiter = mapData.find(L"����");

        if (mapiter == mapData.end())
        {
            std::wcout << L"�ƹ��� ã�� ���߽��ϴ�" << std::endl;
        }
        else
        {
            std::wcout << L"�̸� : " << mapiter->second.m_stName << std::endl;
            std::wcout << L"���� : " << mapiter->second.m_Age << std::endl;
            std::wcout << L"���� : ";
            if ((char)Gender::MAN == mapiter->second.m_Gender)
            {
                std::wcout << L"����" << std::endl;
            }
            else if ((char)Gender::WOMAN == mapiter->second.m_Gender)
            {
                std::wcout << L"����" << std::endl;
            }

            else
            {
                std::wcout << L"�ƹ��͵� ã�� ���߽��ϴ�." << std::endl;
            }

        }



    }

    {

        wstring str1;
        wstring str2;

        str1 = L"test";
        str2 = L"testabcdefg";

        str1 = L"ffffffff";

        str1 += L"abc";

        str1[1] = L'k';

        if (str1 == str2)
        {
            std::cout << "���ڿ��� ���� �����ϴ�" << std::endl;
        }
        else
        {
            std::cout << "���ڿ��� ���� �ٸ��ϴ�" << std::endl;
        }


    }
#pragma endregion


    CBST<int, int> BstInt;

    FPair<int, int> pair;

    pair.first = 100;
    BstInt.insert(pair);
    pair.first = 60;
    BstInt.insert(pair);
    pair.first = 25;
    BstInt.insert(pair);
    pair.first = 200;
    BstInt.insert(pair);
    pair.first = 300;
    BstInt.insert(pair);

    



    return 0;
}