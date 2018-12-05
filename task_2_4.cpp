#include <iostream>
#include <utility>

struct A {
	A() = default;
	A(const A&) { std::cout << __FUNCSIG__ << std::endl; }
	A& operator=(const A&) { std::cout << __FUNCSIG__ << std::endl; return *this; }
	A(A&&) { std::cout << __FUNCSIG__ << std::endl; }
	A& operator=(A&&) { std::cout << __FUNCSIG__ << std::endl; return *this; }
};

template <typename T, typename ... Args>
auto apply(T& f, Args && ... arg) -> decltype(f(std::forward<Args>(arg)...)) {
	return f(std::forward<Args>(arg)...);
}

void task_2_4() {

	auto fun = [](std::string a, std::string const& b) { return a += b; };

	std::string s("world!");

	// s передаётся по lvalue ссылке,
	// а временный объект по rvalue ссылке 
	s = apply(fun, std::string("Hello, "), s);
	return;
}