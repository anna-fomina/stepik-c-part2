#include <typeinfo>
#include <typeindex>
#include "multimethod2.h"

// ������� ����� ������ (�����������)
struct Shape { virtual ~Shape() {} };

// �������������
struct Rectangle : Shape { };

// �����������
struct Triangle : Shape { };

// ������� ��� �������� ����������� ���� ���������������
bool is_intersect_r_r(Shape * a, Shape * b) { return true; }

// ������� ��� �������� ����������� �������������� � ������������
bool is_intersect_r_t(Shape * a, Shape * b) { return true; }

void task_3_3() {
	// ����������� ��� ����������� Shape
	// ����������� bool � ���������� ������������� 
	Multimethod2<Shape, bool, true> is_intersect;

	// ��������� ���������� ������������ ��� ���� ���������������
	is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);

	// ��������� ���������� ������������ ��� �������������� � ������������
	is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);

	// ������ ��� ������    
	Shape * s1 = new Triangle();
	Shape * s2 = new Rectangle();

	//// ���������, ��� ���������� ��� s1 � s2 ����
	if (is_intersect.hasImpl(s1, s2))
	{
		// ���������� ������� is_intersect_r_t(s2, s1)
		bool res = is_intersect.call(s1, s2);

	//	// ���������: is_intersect_r_t �������,
	//	// ��� ������ ���������� ����� �������������
	//	// � ������ �����������, � ����� ���������
	//	// ���������� � �������� �������. 
	//	// ���� ���������� ������ �������������� 
	//	// �� ���� ������������
	}

	return;
}