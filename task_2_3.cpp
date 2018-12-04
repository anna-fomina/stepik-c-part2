#include <tuple>
#include <utility>
#include <iostream>

template<size_t N, size_t M, typename... Args>
auto to_pair(std::tuple<Args...> const &t) -> decltype(std::make_pair(std::get<N>(t), std::get<M>(t))) {
	return std::make_pair(std::get<N>(t), std::get<M>(t));
}

void task_2_3() {

	auto t = std::make_tuple(0, 3.5, "Hello");
	std::pair<double, char const *> p = to_pair<1, 2>(t);
	//auto p = to_pair<1, 2>(t);

	std::cout << '(' << std::get<0>(p) << ", " << std::get<1>(p) << ')' << std::endl;
	
	return;
}