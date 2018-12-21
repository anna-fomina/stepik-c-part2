#include <utility>
#include <iostream>
#include <type_traits>

// внутри do_math объекты типа T
// - копируются
// - присваиваются
// - складываются оператором +
template<class T>
void do_math() noexcept(
	noexcept(T(std::declval<T&>())) && 
	noexcept(std::declval<T>() + std::declval<T>()) &&
	noexcept(std::declval<T&>() = std::declval<T&>()) &&
	noexcept(std::declval<T&>() = std::declval<T&&>()) &&
	noexcept(T(std::declval<T&&>()))
	)
{
	// тело функции нужно оставить пустым
}

void task_4_3()
{
	bool b1 = noexcept(do_math<int>()); // true

	bool b2 = noexcept(do_math<std::string>()); // false

	std::cout << b1 << " " << b2 << std::endl;
}