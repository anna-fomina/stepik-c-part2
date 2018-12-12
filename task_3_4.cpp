#include "vectorlist.h"
#include <iostream>
#include <string>

void task_3_4() {
	
	std::vector<std::string> v1 = { "one", "two", "three" };
	std::vector<std::string> v2 = { "four", "five", "six", "seven", "eight" };
	std::vector<std::string> v3 = { "nine", "ten", "eleven", "twelve" };
	std::vector<std::string> v4 = {};
	for (int k = 13; k <= 30; ++k) {
		v4.push_back(std::to_string(k) + "-th");
	}
	VectorList<std::string> vl;
	std::cout << "empty distance = " << std::distance(vl.rbegin(), vl.rend()) << std::endl;

	vl.append(v1.begin(), v1.end());

	vl.append(v2.begin(), v2.end());

	vl.append(v3.begin(), v3.end());

	vl.append(v4.begin(), v4.end());

	VectorList<std::string>::const_iterator it = vl.begin();
	for (; it != vl.end(); ++it) {
		std::string a = *it;
		std::cout << a << " ";
	}
	std::cout << std::endl;
	std::cout << "distance = " << std::distance(vl.begin(), vl.end()) << std::endl;

	VectorList<std::string>::const_iterator eit = vl.end();
	for (; eit != vl.begin();) {
		std::string a = *(--eit);
		std::cout << a << " ";
	}
	std::cout << std::endl;

	for (; eit != vl.end(); ++eit) {
		std::string a = *(eit);
		std::cout << a << " ";
	}
	std::cout << std::endl;

	VectorList<std::string>::const_reverse_iterator rit = vl.rend();
	for (; rit != vl.rend(); ++rit) {
		std::string a = *rit;
		std::cout << a << " ";
	}
	std::cout << std::endl;
	std::cout << "reverse distance = " << std::distance(vl.rbegin(), vl.rend()) << std::endl;

	VectorList<std::string>::const_reverse_iterator erit = vl.rend();
	for (; erit != vl.rbegin();) {
		std::string a = *(--erit);
		std::cout << a << " ";
	}
	std::cout << std::endl;

	VectorList<std::string>::const_iterator i = vl.rend().base();
	for (; i != vl.end(); ++i) {
		std::string a = *i;
		std::cout << a << " ";
	}

	std::cout << std::endl;
	
	return;

}