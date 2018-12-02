#include "tasks.h"
#include <typeinfo>
#include "unit.h"
#include <iostream>
#include <algorithm>



template<typename T, typename U>
bool compare(T const &a, T const &b, U (T::*mptr)() const) {
	return ((a.*mptr)() < (b.*mptr)()) ? true : false;
}

typedef int * (Unit::*Foo) (int, double) const;
//using Foo = int * (Class::*) (int, double) const;

void test() {
	std::string s1("Elf");
	std::string s2("Archer");

	bool r1 = compare(s1, s2, &std::string::size);
	bool r2 = compare(s2, s1, &std::string::size);
	std::cout << r1 << " " << r2 << std::endl;
}