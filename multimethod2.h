#pragma once

#include <typeinfo>
#include <typeindex>
#include <map>
#include <functional>
#include <utility>

// Base - базовый класс иерархии
// Result - тип возвращаемого значения мультиметода
// Commutative - флаг, который показывает, что
// мультиметод коммутативный (т.е. f(x,y) = f(y,x)).
template<class Base, class Result, bool Commutative>
struct Multimethod2
{
	typedef std::pair<std::type_index, std::type_index> types;
	typedef std::function<Result(Base *, Base *)> func;
	// устанавливает реализацию мультиметода
	// для типов t1 и t2 заданных через typeid 
	// f - это функция или функциональный объект
	// принимающий два указателя на Base 
	// и возвращающий значение типа Result
	void addImpl(std::type_index t1, std::type_index t2, func f)
	{
		mult.insert({ { t1, t2 }, f });
	}

	// проверяет, есть ли реализация мультиметода
	// для типов объектов a и b
	bool hasImpl(Base * a, Base * b) const
	{
		std::type_index t1 = typeid(*a);
		std::type_index t2 = typeid(*b);
		if ((mult.find(std::make_pair(t1, t2)) != mult.end()) ||
			((Commutative) && (mult.find(std::make_pair(t2, t1)) != mult.end()))) {
			return true;
		}
		return false;

	}

	// Применяет мультиметод к объектам
	// по указателям a и b
	Result call(Base * a, Base * b) const
	{
		std::type_index t1 = typeid(*a);
		std::type_index t2 = typeid(*b);
		auto it = mult.find(std::make_pair(t1, t2));
		if ( (Commutative) && (it == mult.end()) ) {
			it = mult.find(std::make_pair(t2, t1));
			return it->second(b, a);
		}
		else {
			return it->second(a, b);
		}
	}
private:
	std::map<types, func> mult;
};