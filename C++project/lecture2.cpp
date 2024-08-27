#include "lectures.h"

//c++에서의 포인터 ... 참조자에 대한 이해

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void changeval(int& p) {//선언과 동시에 초기화가 안 되었는데 되는 이유는 : 스택 안에서 int&p=10;이라는게 새로 생기기 때문
	p = 10;
}
//int를 반환하는 함수
int function2() {
	int a = 2;
	return a;
}

//참조자를 리턴하는 함수
//사용하면 안되는 함수 ,,아직 이해안됨
int& function() {
	int a = 2;
	return a;
}

typedef struct Human {
	char name[30];
	int age;
}Human;

Human& addhumaninfo(Human& human) {
}

int printhumaninfo() {

}

void lecture2()
{
	int num = 10;
	int* numptr = &num;
	std::cout << "포인터가 가리키는 값:" << *numptr << std::endl;//c언어와 달리c++은 데이터의 형태 명시 불필요 %s,%d,%p...
	int num1 = 3;
	int num2 = 4;
	swap(&num1, &num2);
	std::cout<<num1<<num2<<std::endl;

	//참조자 만드는 법
	//참조자=변수의 별명으로 이해
	int a1 = 10;
	int& A1 = a1;
	int dnum1 = 1;
	int dnum2 = 2;
	swap(dnum1, dnum2);
	std::cout << dnum1 << dnum2 << std::endl;
	//참조자는 반드시 선언과 동시에 초기화가 되어야 함
	int changenum = 5;
	changeval(changenum);
	std::cout << changenum << std::endl;

	int tempa = function();
	int tempb = function2();

	//레퍼런스 타입을 리턴할 때는 반드시 지역변수를 반환하지 않게 조심.

	std::cout << tempa << std::endl;
	std::cout << tempb << std::endl;

	const int& anothertemp = function();//이해안됨

	Human human;


}
