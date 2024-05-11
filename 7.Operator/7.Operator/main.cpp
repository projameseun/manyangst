#include <iostream>
using namespace std;

void Func1()
{
	int a = 0;

	a = 200;
}

int main()
{

	//operator 연산자
	//+ , - , / , * , %(모듈러스)

	std::cout << "10 + 5 = " << (10 + 5) << std::endl;
	std::cout << "10 - 5 = " << (10 - 5) << std::endl;
	std::cout << "10 * 5 = " << (10 * 5) << std::endl;
	std::cout << "10 / 5 = " << (10 / 5) << std::endl;
	std::cout << "10 % 5 = " << (10 % 5) << std::endl;

	//모듈러스 연산자는 A를 B로 나누었을때 몫을 제외한 나머지를 구해진다.
	//10 % 5 = 0 이되는 것이다.

	//모듈러스 연산자를 이용하면 2로 나누었을때 나머지가 0이되면 짝수이다. 짝수를 뺀 나머지는 홀수이다.
	
	//연산자 축약형
	//+= ,-= *=,/=,%= 등 모든 연산자들은 축약해서 사용이 가능하다.

	int a = 0;

	a = a + 1;

	a += 1; //a = a + 1; (같은 말이다)

	a *= 3; //a = a * 3;


	std::cout << a << std::endl;

	//증감 연산자
	//++,--
	//전위,후위

	int idata = 0;
	
	//++idata;
	//idata++;

	a = 0;

	int iNumber = 20;
	int iNumber2 = 50;

	//iNumber += a++;
	iNumber += a++;
	
	
	std::cout << "idata = " << idata << std::endl;

	std::cout << "iNumber = " << iNumber << std::endl;

	//후위연산자는 말 그대로 값을 먼저 대입을 시키고 증가 한다는 의미이다.
	//증감 연산자는 단독으로 사용 할 때는 큰 차이가 없지만 변수를 넣었을때는 얘기가 다르다.
	//연산자 우선순위에 의해서 대입연산자가 먼저 일어나기 때문이다.
	//그래서 후위 와 전위를 변수에 넣었을때 분명한 차이가 있다.

	//전위연산자는 l-value 
	//후위연산자는 r-value
	
	//l-value :대입연산자(=)의 왼쪽에 올수 있는 표현식을 가리킨다.
	//메모리에 저장된 위치를 나타내며,변경할 수 있다.

	//r-value:대입연산자(=)의 오른쪽에 올수 있는 표현식을 가리킨다.
	//값 자체를 나타내며 , 변경을 할 수가 없다.

	//const는 상수이며 값을 변경 할수 없다. 그래서 착각하는게 r-value라고 생각할수 있지만 const는 변경 할수 없는 l-value이다.
	//const 가 붙은 변수는 메모리의 위치는 가지고 있으므로 l-value이다.

	//전위 연산자
	//먼저 값을 증가 시키고 그 결과 값을 반환한다.
	//ex)iNumber += ++a
	//1.메모리에 있는 a에 직접 값을 1증가시킨다  
	//2.그리고 a를 반환한다
	//3.그 반환값을 iNumber + 해준다.
	//3.a자체를 반환했기때문에 이는 참조(주소)값을 가지고 있다는 뜻이 된다.

	//후위 연산자
	//전위와 다르게 추가적인게 필요하다
	//ex) iNumber += a++;
	//1.먼저 iNumber에 a변수를 대입하고 값을 변화시키는게 특징이다.
	//2.변화 한 값을 연산을 먼저하고 가져오기 때문에 임시메모리가 필요하다.
	//3.a에 1을 더한 값을 임시메모리(temp)에 저장해 놓는다.
	//4.그리고 a에(원본) 값을 iNumber 더해준다.
	//5.근데 이때 a는 변경된 값이 아니라 기존값이 들어있기때문에 절대 변경되면 안되서 const를 반환한다.
	//6.풀이를 해보면 iNumber = iNumber +a(원본)이 되는것이다.

	a = 0;

	++a = 100;
	

	//a++ = 10; //왼쪽에 r-value가 들어와서 error이다 풀이해보면 0 = 100;
	
	//결론
	//둘다 증가된값을 리턴하지만 ++a는 증가된 a자신을 리턴하기때문에 l-value인 반면에 a++은 증가된 복사본을 리턴하기때문에 R-value이다.



	a = 100;

	a--;

	//논리연산자 
	//!(NOT) , &&(AND) , ||(OR)
	//논리 연산자는 참/거짓을 연산하여 결과로 참/거짓이 나온다.

	/*
		A		B		AND		OR
		false	false	false	false
		false	true	false	true
		true	false	false	true
		true	true	true	true
	
		AND는 둘다 true 일때 true이고 아니면 false이다
		OR는 둘중 하나라도 true일때 아니면 false이다.

		A		NOT
		false	true
		true	false
		NOT는 반전이 된다.

		true =1;
		false =0;
		
	*/
	
	std::cout << "false && false =" << (false && false) << std::endl;		//0
	std::cout << "false && true=" << (false && true) << std::endl;			//0
	std::cout << "true && false =" << (true && false) << std::endl;			//0
	std::cout << "true && true=" << (true && true) << std::endl;			//1

	std::cout << "false || false =" << (false || false) << std::endl;		//0
	std::cout << "false ||true=" << (false || true) << std::endl;			//1
	std::cout << "true || false =" << (true || false) << std::endl;			//1
	std::cout << "true ||true=" << (true || true) << std::endl;				//1

	std::cout << "!false  =" << !false << std::endl;						//1
	std::cout << "!true=" << !true << std::endl;							//0

	/*
		관계연산자
		< , > , <= , >= , ==(같다) ,!=(다르다)
		관게연산자는 값대 값을 연산하여 참/거짓으로 출력을 하게 된다.
	*/

	std::cout <<  "100 < 200 = " << (100 < 200) << std::endl; //1
	std::cout <<  "100 > 200 = " << (100 > 200) << std::endl; //0
	std::cout <<  "100 <= 200 = " << (100 <= 200) << std::endl; //1
	std::cout <<  "100 >= 200 = " << (100 >= 200) << std::endl; //0
	std::cout <<  "100 == 200 = " << (100 == 200) << std::endl; //0
	std::cout <<  "100 != 200 = " << (100 != 200) << std::endl; //1


		return 0;
}