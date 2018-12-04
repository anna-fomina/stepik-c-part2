#include <tuple>
#include <utility>
#include <iostream>
#include "point.h"

template<size_t N, size_t M, typename... Args>
auto to_pair(std::tuple<Args...> const &t) -> decltype(std::make_pair(std::get<N>(t), std::get<M>(t))) {
	return std::make_pair(std::get<N>(t), std::get<M>(t));
}

template<class F>
void for_each_int(int * p, int * q, F f)
{
	for (; p != q; ++p)
		f(*p);
}

template<class F>
int * find_if(int * p, int * q, F f)
{
	for (; p != q; ++p)
		if (f(*p))
			return p;
	return q;
}

void task_2_3() {

	//task 2.3.1
	auto t = std::make_tuple(0, 3.5, "Hello");
	std::pair<double, char const *> p = to_pair<1, 2>(t);
	std::cout << '(' << std::get<0>(p) << ", " << std::get<1>(p) << ')' << std::endl;

	//task 2.3.2
	constexpr size_t size = static_cast<size_t>(Point(2, 4) * Point(4, 3));
	int m2[size]; // массив из 20 элементов

	//task 2.3.3
	int m3[10] = { 1,2,3,4,5,6,7,8,9,10 };
	auto square_fun = [](int &x) { x *= x; };
	for_each_int(m3, m3 + 10, square_fun); // теперь m = {1,4,9,16,25,36,49,64,81,100};

	//task 2.3.4
	int primes[5] = { 2,3,5,7,11 };

	int m[10] = { 0,0,1,1,4,6,7,8,9,10 };

	auto gen_finder = [](int * p, int * q) {
		return[p, q] (int x) {
			int * pp = p;
			for (; pp != q; ++pp) {
				if (*pp == x) {
					return true;
				}
			}
			return false;
		};
	};
	// first_prime будет указывать на число 7
	int * first_prime = find_if(m, m + 10, gen_finder(primes, primes + 5));
	return;
}