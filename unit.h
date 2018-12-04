#pragma once
#include <string>

struct Unit
{
explicit Unit(size_t id)
: id_(id)
{}

size_t id() const { return id_; }
virtual ~Unit() {};

private:
size_t id_;
};

// ������� ����� ��� ��������
struct Animal : virtual Unit
{
	// name ������ �������� ���������
	// "bear" ��� �������
	// "pig" ��� ������
	Animal(std::string const & name, size_t id) : Unit(id), name_(name) {}

	std::string const& name() const { return name_; }
private:
	std::string name_;
};

// ����� ��� ��������
struct Man : virtual Unit
{
	explicit Man(size_t id = 50) : Unit(id) {}
};

// ����� ��� �������
struct Bear : Animal
{
	explicit Bear(size_t id = 100) : Animal("bear", id), Unit(id) {}
};

// ����� ��� ������
struct Pig : Animal
{
	explicit Pig(size_t id = 300) : Animal("pig", id), Unit(id) {}
};

// ����� ��� ���������������
struct ManBearPig : Man, Bear, Pig
{
	ManBearPig(size_t id = 80) : Bear(id), Pig(id), Man(id), Unit(id) {}
	// ...
};
