#include "tasks.h"
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

//
//struct ElementN
//{
//	explicit ElementN(size_t n)
//		: n(n), i(0)
//	{}
//
//	template<class T>
//	bool operator()(T const& t) { return (i++ == n); }
//
//	size_t n;
//	size_t i;
//};

//2
//struct ElementN
//{
//	explicit ElementN(size_t n)
//		: n(n)
//	{}
//
//	template<class T>
//	bool operator()(T const& t) { return (i++ == n); }
//
//	size_t n;
//	static size_t i;
//};
//
//size_t ElementN::i = 0;

//struct ElementN
//{
//	explicit ElementN(size_t n)
//		: n(n), pi(new size_t(0))
//	{}
//
//	template<class T>
//	bool operator()(T const& t) { return ((*pi)++ == n); }
//
//	~ElementN() { delete pi; }
//
//	size_t n;
//	size_t * pi;
//};

////4
//struct ElementN
//{
//	explicit ElementN(size_t n)
//		: n(n), pi(new size_t(0))
//	{}
//
//	template<class T>
//	bool operator()(T const& t) { 
//		std::cout << *pi << std::endl;
//		return ((*pi)++ == n); 
//	}
//
//	size_t n;
//	std::shared_ptr<size_t> pi;
//};
//5
//struct ElementN
//{
//	explicit ElementN(size_t n)
//		: n(n), pi(new size_t(0))
//	{}
//
//	template<class T>
//	bool operator()(T const& t) { return ((*pi)++ == n); }
//
//	size_t n;
//	std::unique_ptr<size_t> pi;
//};

//6
struct ElementN
{
	explicit ElementN(size_t n)
		: n(n)
	{}

	template<class T>
	bool operator()(T const& t)
	{
		static size_t i = 0;
		std::cout << i << std::endl;
		return (i++ == n);
	}

	size_t n;
};

template<class Iterator, class Pred>
Iterator my_remove_if(Iterator p, Iterator q, Pred pred)
{
	Iterator s = find_if(p, q, pred);
	if (s == q)
		return q;

	Iterator out = s;
	++s;
	return std::remove_copy_if(s, q, out, pred);
}

void test() {
	/*std::vector<int> v = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };

	v.erase(my_remove_if(v.begin(), v.end(), ElementN(3)), v.end());

	for (int i : v)
		std::cout << i << ' ';*/

	ElementN eln(5);
	ElementN eln_copy_1 = eln;
	ElementN eln_copy_2 = eln;
	ElementN elnNew(6);
	std::cout << std::boolalpha;
	for (int i = 0; i < 10; ++i)
		std::cout << eln_copy_1(i) << '\n';
	for (int i = 0; i < 10; ++i)
		std::cout << eln(i) << '\n';
	for (int i = 0; i < 10; ++i)
		std::cout << eln_copy_2(i) << '\n';
	for (int i = 0; i < 10; ++i)
		std::cout << elnNew(i) << '\n';

}