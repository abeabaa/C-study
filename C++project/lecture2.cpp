#include "lectures.h"

//c++������ ������ ... �����ڿ� ���� ����

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

void changeval(int& p) {//����� ���ÿ� �ʱ�ȭ�� �� �Ǿ��µ� �Ǵ� ������ : ���� �ȿ��� int&p=10;�̶�°� ���� ����� ����
	p = 10;
}
//int�� ��ȯ�ϴ� �Լ�
int function2() {
	int a = 2;
	return a;
}

//�����ڸ� �����ϴ� �Լ�
//����ϸ� �ȵǴ� �Լ� ,,���� ���ؾȵ�
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
	std::cout << "�����Ͱ� ����Ű�� ��:" << *numptr << std::endl;//c���� �޸�c++�� �������� ���� ��� ���ʿ� %s,%d,%p...
	int num1 = 3;
	int num2 = 4;
	swap(&num1, &num2);
	std::cout<<num1<<num2<<std::endl;

	//������ ����� ��
	//������=������ �������� ����
	int a1 = 10;
	int& A1 = a1;
	int dnum1 = 1;
	int dnum2 = 2;
	swap(dnum1, dnum2);
	std::cout << dnum1 << dnum2 << std::endl;
	//�����ڴ� �ݵ�� ����� ���ÿ� �ʱ�ȭ�� �Ǿ�� ��
	int changenum = 5;
	changeval(changenum);
	std::cout << changenum << std::endl;

	int tempa = function();
	int tempb = function2();

	//���۷��� Ÿ���� ������ ���� �ݵ�� ���������� ��ȯ���� �ʰ� ����.

	std::cout << tempa << std::endl;
	std::cout << tempb << std::endl;

	const int& anothertemp = function();//���ؾȵ�

	Human human;


}
