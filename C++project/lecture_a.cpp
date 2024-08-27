#include "lectures.h"
#include <cstring>

class point {
private:
	int posx, posy;
public:
	point() {}   //����Ʈ ������
	point(int x, int y) {//������ �����ε�
		posx = x;
		posy = y;
	}
	void showposition() {
		std::cout << posx <<"," << posy << std::endl;
	}
	point operator+(point& ref) {//��ȯ���� point�� ������ �ΰ��� point��ü�� ���ؼ� ���ο� point��ü�� ������ �ϱ� ����
		return point(posx + ref.posx, posy + ref.posy);
	}
	point operator-(point& ref) {//p1 - p2 ǥ������ ���� ��, �����Ϸ��� p1.operator-(p2)�� �ؼ�
		return point(posx - ref.posx, posy - ref.posy);
	}
	point operator+(int num) {
		return point(posx + num, posy + num);
	}
	friend point operator+(int num, point ref);
	//friend�Լ� : Ŭ������ ����Լ��� �ƴϸ鼭 �ش� Ŭ������ private�����͸� ������ �� ����ϴ� �Լ� + Ŭ������ ������ �ʱ� ������
	//�ش� operator+()�� �����Լ��� �ȴ�.

	point operator++() {//�������� ������
		posx += 1;
		posy += 1;
		return *this;//�ڱ� �ڽ��� ��ü�� ��ȯ(�ڽ��� ���������� ��ȯ)
	}

	point operator++(int) {//�������� ������, operator++(int) ��ȣ�ȿ� int�� ������ �ϸ� �����Ϸ��� ���������� �ν�
		point temp(*this);//���� ������:���� ����� �����Ͱ� �̵�, ����������� ����:
		//point temp()���� pointŸ���� temp��ü�� �����ǰ� ���ڷ� *this�� ���� �� ��ü�� �ޱ� ������ temp��ü�� ���� �� ��ü�� �μ��� �޾� �ʱ�ȭ��
		// ���� ��ü�� ���纻�� ����
		posx += 1;
		posy += 1;// ... (���� ���� �� ��Ÿ �۾�)
		return temp;// ���� ���� ���¸� ��ȯ , �������� �������̱� ����
	}
};
point operator+(int num, point ref) {//Ŭ������ ������ ���� �����Լ��̱� ������ point::operator+()�� ���� ����. ��ȯ���� pointŬ������ ��
	//ref.posx +num; ������ ���� � �������� �������� �ʾұ� ������ �ȵ�
	ref.posx += num;
	ref.posy += num;
	return ref;
}



class eng;
class math {
	char name[10];
	int score;
public:
	math() {};//����Ʈ �����ڴ� �ٸ� �����ڸ� �����ϸ� ������ �ʱ� ������ ��������� �����Ͽ� ����� �� �ְ� ��.
	math(const char* name,int score) {//const char* name�� ������ ���� "����"�̶�� �ϸ� ���ͷ� ���ڿ��̶� �ּҰ��� �ٲܼ� ���� ����
									  //�����޸𸮿� ����Ǳ� ������ �� ��ġ�� �����ϴ� ���� �б������̰� �ش� ��ġ�� �޸𸮴� ���� �Ұ�
		strcpy_s(this->name, 10, name);
		this->score = score;
	}
	friend int add(math m1, eng e1);
};

//int add(math m1, eng e1) {
//	return m1.score + e1.score;//�̰� �ȵǴ� ������ engŬ������ �տ� ���ǵǾ����� �ʱ� ����
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
	//point result = p1 + p2;//�ش��ϴ� �ǿ����ڰ� ���ٰ� �߱� ������ �� �����ڸ� ������ָ� �� (������ �����ε�)ex.// void operator+();//
	//������ �����ε� : (��ȯ��) (Ű����)(������)()
	point pluswithnum = p1 + 10;
	pluswithnum.showposition();

	point numwithplus = 10 + p1;//10.operator+(point&p1);�� �����Լ����� ã�� �Ǵµ� point operator+(int num, point ref)�� �����Լ��� ����� ���
	//������ ����
	numwithplus.showposition();
	point p3(3, 3);
	++p3;
	p3.showposition();
	point p4(4, 4);
	p4++;
	p4.showposition();
	math m1("����", 95), m2("����", 70);
	eng e1("����", 80), e2("����", 60);

	std::cout << add(m1, e2) << std::endl;
}