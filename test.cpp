#include "tasks.h"
#include "unit.h"
#include <iostream>
#include <memory>




void test() {
	std::unique_ptr<Unit> p1(new Bear);

	std::unique_ptr<Unit> p2(std::move(p1));
}