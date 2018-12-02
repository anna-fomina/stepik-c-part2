#include "tasks.h"
#include <iostream>
#include <typeinfo>

void print_values(std::ostream & os) {
	return;
}

template<typename T, typename... Args>
void print_values(std::ostream & os, T const & value, Args const & ... args) {
	os << typeid(value).name() << ": " << value << "\n";
	print_values(os, args...);
}


void task_2_1() {
	print_values(std::cout, 0, 3.5, "Hello");
	return;
}