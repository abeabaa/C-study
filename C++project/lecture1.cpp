#include "lectures.h"

//�̸�����namespace
//std�� c++ǥ�� ���̺귯���� ��� �Լ��� ���ǵ� �̸�����
//:: -> ��������������
//using������

void lecture1()
{
	std::cout << "Hello" << std::endl;
	int luckynumber = 5;
	int userinput;
	std::cout << "���ڸ� �Է�";
	while (1) {
		std::cin >> userinput;
		if (luckynumber == userinput) {
			std::cout << "����";
			break;
		}
		else std::cout << "���ڸ� �Է�";
	}
}
