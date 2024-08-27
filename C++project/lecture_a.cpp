#include "lectures.h"
#include <cstring>

class point {
private:
	int posx, posy;
public:
	point() {}   //디폴트 생성자
	point(int x, int y) {//생성자 오버로딩
		posx = x;
		posy = y;
	}
	void showposition() {
		std::cout << posx <<"," << posy << std::endl;
	}
	point operator+(point& ref) {//반환값이 point인 이유는 두개의 point객체를 더해서 새로운 point객체를 만들어야 하기 때문
		return point(posx + ref.posx, posy + ref.posy);
	}
	point operator-(point& ref) {//p1 - p2 표현식이 있을 때, 컴파일러는 p1.operator-(p2)로 해석
		return point(posx - ref.posx, posy - ref.posy);
	}
	point operator+(int num) {
		return point(posx + num, posy + num);
	}
	friend point operator+(int num, point ref);
	//friend함수 : 클래스의 멤버함수가 아니면서 해당 클래스의 private데이터를 접근할 때 사용하는 함수 + 클래스에 속하지 않기 때문에
	//해당 operator+()는 전역함수가 된다.

	point operator++() {//전위증가 연산자
		posx += 1;
		posy += 1;
		return *this;//자기 자신을 개체로 반환(자신의 역참조값을 반환)
	}

	point operator++(int) {//후위증가 연산자, operator++(int) 괄호안에 int를 넣으면 하면 컴파일러가 후위증가로 인식
		point temp(*this);//복사 생성자:얕은 복사로 데이터가 이동, 복사생성자인 이유:
		//point temp()에서 point타입의 temp객체가 생성되고 인자로 *this즉 현재 이 객체를 받기 때문에 temp객체는 현재 이 객체를 인수로 받아 초기화됨
		// 현재 객체의 복사본을 생성
		posx += 1;
		posy += 1;// ... (증가 연산 및 기타 작업)
		return temp;// 증가 전의 상태를 반환 , 후위증가 연산자이기 때문
	}
};
point operator+(int num, point ref) {//클래스에 속하지 않은 전역함수이기 때문에 point::operator+()로 하지 않음. 반환값은 point클래스가 됨
	//ref.posx +num; 저장한 값을 어떤 변수에도 저장하지 않았기 때문에 안됨
	ref.posx += num;
	ref.posy += num;
	return ref;
}



class eng;
class math {
	char name[10];
	int score;
public:
	math() {};//디폴트 생성자는 다른 생성자를 정의하면 생기지 않기 때문에 명시적으로 생성하여 사용할 수 있게 함.
	math(const char* name,int score) {//const char* name인 이유는 예로 "수학"이라고 하면 리터럴 문자열이라서 주소값을 바꿀수 없기 때문
									  //정적메모리에 저장되기 때문에 이 위치는 실행하는 동안 읽기전용이고 해당 위치의 메모리는 변경 불가
		strcpy_s(this->name, 10, name);
		this->score = score;
	}
	friend int add(math m1, eng e1);
};

//int add(math m1, eng e1) {
//	return m1.score + e1.score;//이게 안되는 이유는 eng클래스가 앞에 정의되어있지 않기 때문
//}

class eng {
	char name[10];
	int score;
public:
	eng() {};
	eng(const char* name, int score) {
		strcpy_s(this->name, 10, name);
		this->score = score;
	}
	friend int add(math m1, eng e1);
};

int add(math m1, eng e1) {
	return m1.score + e1.score;
}

void lecture_a() {
	point p1(1, 1);
	point p2(2, 3);
	p1.showposition();
	point result = p1 + p2;
	point result1 = p2 - p1;
	result.showposition();
	result1.showposition();
	//point result = p1 + p2;//해당하는 피연산자가 없다고 뜨기 때문에 그 연산자를 만들어주면 됨 (연산자 오버로딩)ex.// void operator+();//
	//연산자 오버로딩 : (반환값) (키워드)(연산자)()
	point pluswithnum = p1 + 10;
	pluswithnum.showposition();

	point numwithplus = 10 + p1;//10.operator+(point&p1);를 전역함수에서 찾게 되는데 point operator+(int num, point ref)로 전역함수로 만들어 줬기
	//때문에 가능
	numwithplus.showposition();
	point p3(3, 3);
	++p3;
	p3.showposition();
	point p4(4, 4);
	p4++;
	p4.showposition();
	math m1("수학", 95), m2("수학", 70);
	eng e1("영어", 80), e2("영어", 60);

	std::cout << add(m1, e2) << std::endl;
}