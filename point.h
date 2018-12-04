#pragma once

struct Point
{
	constexpr Point(double x, double y)
		: x(x), y(y)
	{}

	double x = 0;
	double y = 0;
};

constexpr Point operator+(Point const& p1, Point const& p2) {
	return Point(p1.x + p2.x, p1.y + p2.y);
}

constexpr Point operator-(Point const& p1, Point const& p2) {
	return Point(p1.x - p2.x, p1.y - p2.y);
}

constexpr double operator*(Point const& p1, Point const& p2) {
	return p1.x * p2.x + p1.y * p2.y;
}



