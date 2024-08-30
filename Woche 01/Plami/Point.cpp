#include <iostream>

struct Point
{
	double x = 0.;

	double y = 0.;

	void printPoint()
	{
		std::cout << '(' << x << ', ' << y << ')' << std::endl;
	}

	short getQuadrant()
	{
		if (x == 0 || y == 0)
			return -1;

		if (x > 0 && y > 0)
			return 1;
		else if (x < 0 && y > 0)
			return 2;
		else if (x < 0 && y < 0)
			return 3;
		else if(x > 0 && y < 0)
			return 4;
	}
};

float getDistance(const Point& lhs, const Point& rhs)
{
	return sqrt((rhs.x - lhs.x)*(rhs.x - lhs.x) + (rhs.y - lhs.y)*(rhs.y - lhs.y));
}

bool isInCircle(const Point& point, float radius)
{
	return (getDistance({ 0,0 }, point) <= radius);
}


Point initPoint()
{
	Point result;

	std::cin >> result.x >> result.y;

	return result;
}

int main()
{
	Point p1 = initPoint();

	Point p2 = initPoint();
	
	std::cout << getDistance(p1, p2) << std::endl;

	std::cout << p2.getQuadrant() << std::endl;

	std::cout << isInCircle(p1,5) << std::endl;

	std::cout << isInCircle(p2,2) << std::endl;

	return 0;
}