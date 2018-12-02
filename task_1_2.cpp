#include <iostream>

struct Base {
	int x;
	Base(int x = 0) : x(x) {}
	virtual void print() const {
		std::cout << "Base" << std::endl;
	}
};

struct D1 : Base {
	void print() const {
		std::cout << "D1" << std::endl;
	}
};

struct D2 : Base {
	void print() const {
		std::cout << "D2" << std::endl;
	}
};

struct D3 : D1, D2 {
};

Base const * D1BaseToD2Base(Base const * base)
{
	return (Base*)(D2*)(D3*)(D1*)base;
}

void task_1_2() {
	
	//D3 p;
	//D1 * d1 = &p;
	//Base * d1base = d1;
	//d1base->print();
	//Base const * d2base = D1BaseToD2Base(d1base);
	//d2base->print();

	int a = 27;
	int const b = 412;
	int * pa = &a;

	//int const c = a;
	//int d = b;
	//int const * p1 = pa;
	//int * const * p2 = &pa;
	//int const ** p3 = &pa;
	return;
}