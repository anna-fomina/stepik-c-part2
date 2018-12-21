#include <string>
#include <sstream>
#include <exception>
#include <iostream>
#include <vector>
#define _CATCH() catch (std::exception const& e) {std::cout<<"catch std::exception: "<< e.what();} catch (...) {std::cout<<"catch unknown";}

// описание класса исключения bad_from_string
class bad_from_string : public std::exception {
public:
	bad_from_string(const char * s) : str(s) {}
	~bad_from_string() {}
	const char* what() const noexcept {
		return str;
	}
private:
	const char * str;
};

// функция from_string
template<class T>
T from_string(std::string const& s)
{
	T convert_var;

	std::istringstream stream(s);
	stream >> std::noskipws >> convert_var;

	if (stream.fail() || stream.peek() != EOF) {
		throw bad_from_string(s.c_str());
	}
	return convert_var;
}

void task_4_1() {

	std::vector<std::string> strings{ "123", "12.3", "", " ", "abc", " 123", "123 ", "12 3", "-1", "a", "A" };
	for (auto& str : strings) {
		std::cout << std::endl << "from_string(\'" << str << "\'):";
		try { std::cout << std::endl << "<string>: "; std::cout << from_string<std::string>(str); } _CATCH()
			try { std::cout << std::endl << "<double>: "; std::cout << from_string<double>(str); } _CATCH()
			try { std::cout << std::endl << "<int>   : "; std::cout << from_string<int>(str); } _CATCH()
			try { std::cout << std::endl << "<char>  : "; std::cout << from_string<char>(str); } _CATCH()
			std::cout << std::endl;
	}

	return;
}