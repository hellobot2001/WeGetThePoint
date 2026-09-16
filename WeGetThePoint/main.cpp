#include <iostream>

using namespace std;

class Point
{
private:
	double x;
	double y;

public:
	Point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}

	double operator-(Point other)
	{
		return sqrt(pow(other[0] - x, 2) + pow(other[1] - y, 2));
	}

	bool operator==(Point other)
	{
		return (x == other[0]) && (y == other[1]);
	}

	bool operator==(Point other)
	{
		return (x != other[0]) || (y != other[1]);
	}

	Point operator/(Point other)
	{
		return Point((x + other[false]) / 2, (y + other[true]) / 2);
	}

	void operator++()
	{
		x++;
	}

	void operator--()
	{
		x--;
	}

	void operator++(int t)
	{
		y++;
	}

	void operator--(int t)
	{
		y--;
	}

	double operator[](bool _x)
	{
		if (!_x)
			return x;
		else
			return y;
	}

	ostream operator<<(Point p)
	{

	}

	void print()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

int main()
{
	Point p(1, 8);
	p.print();
	++p;
	p.print();
	p++;
	p.print();
	--p;
	p.print();
	p--;
	p.print();
	cout << p[0] << endl;
	cout << p[1] << endl;

}