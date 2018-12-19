#include <algorithm>
#include <vector>
#include <array>
#include <iostream>

// алгоритм должен работать с forward итераторами
// и возвращать итератор, который потом будет передан
// в метод erase соответствующего контейнера
template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n) {
	size_t m = 0;
	FwdIt result = p;
	for (; p != q; ++p) {
		if (!(m++ == n)) {
			*result++ = *p;
		}
	}
	return result;
}


template<class Iterator>
size_t count_permutations(Iterator p, Iterator q) {
	if (p == q) {
		return 1;
	}
	
	using T = typename std::iterator_traits<Iterator>::value_type;
	std::vector<T> v;
	for (; p != q; ++p) {
		v.push_back(*p);
	}
	std::sort(v.begin(), v.end());

	size_t count = 0;
	do {
		if (std::adjacent_find(v.begin(), v.end()) == v.end()) {
			++count;
		}
	} while (std::next_permutation(v.begin(), v.end()));
	return count;
}

void task_3_5() {

	std::array<int, 2> a1 = {1, 1};
	size_t c1 = count_permutations(a1.cbegin(), a1.cend()); // 6

	std::array<int, 5> a2 = { 1,2,3,4,4 };
	size_t c2 = count_permutations(a2.begin(), a2.end()); // 36

	std::vector<int> v;
	size_t c3 = count_permutations(v.begin(), v.end()); // 36

	std::cout << c1 << " " << c2 << " " << c3 << std::endl;

	return;
}