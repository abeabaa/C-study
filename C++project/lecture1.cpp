#include "lectures.h"

//이름공간namespace
//std는 c++표준 라이브러리의 모든 함수가 정의된 이름공간
//:: -> 범위지정연산자
//using연산자

void lecture1()
{
	std::cout << "Hello" << std::endl;
	int luckynumber = 5;
	int userinput;
	std::cout << "숫자를 입력";
	while (1) {
		std::cin >> userinput;
		if (luckynumber == userinput) {
			std::cout << "정답";
			break;
		}
		else std::cout << "숫자를 입력";
	}
}
