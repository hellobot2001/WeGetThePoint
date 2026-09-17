#include <iostream>
#include <string>

using namespace std;

class Point
{
	friend istream& operator>>(istream& i, Point& p);
private:
	double x;
	double y;

public:
	Point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}

	Point() { x = 0; y = 0; }

	double operator-(Point other)
	{
		return sqrt(pow(other[0] - x, 2) + pow(other[1] - y, 2));
	}

	bool operator==(Point other)
	{
		return (x == other[0]) && (y == other[1]);
	}

	bool operator!=(Point other)
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

	void print()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

ostream& operator<<(ostream& o, Point p)
{
	o << "(" << p[0] << ", " << p[1] << ")";
	return o;
}

void donothing() {}

istream& operator>>(istream& i, Point& p)
{
	string s;
	i >> s;
	//cout << s << endl;
	string num = "";
	int f = 0;
	if (s[f] == '(')
		f++;
	for (f = f; f < s.length(); f++)
	{
		if (s[f] == ',')
			break;
		if (s[f] == ' ')
			break;
		num.append(string(1, s[f]));
	}
	if (s[f] == ',')
		f++;
	if (s[f] == ' ')
		f++;
	//cout << ":" << num << ":" << endl;
	p.x = stod(num);
	num = "";
	//cout << "hello" << endl;
	//cout << f << endl;
	//cout << s.length() << endl;
	//cout << s << endl;
	//cout << s[f] << endl;
	for (f = f; f < s.length(); f++)
	{
		//cout << s[f] << endl;
		if (s[f] == ')')
			break;
		num.append(string(1, s[f]));
	}
	//cout << num << endl;
	p.y = stod(num);
	return i;
}

int main()
{
	Point p(1, 8);
	cout << p << endl;
	++p;
	cout << p << endl;
	p++;
	cout << p << endl;
	--p;
	cout << p << endl;
	p--;
	cout << p << endl;
	cout << p[0] << endl;
	cout << p[1] << endl;

	cout << "enter coordinates in format x,y or (x,y): ";
	Point* v2 = new Point();
	cin >> *v2;
	cout << *v2 << endl;
	cout << *v2 - p << endl;
	cout << *v2 / p << endl;
	cout << ((*v2 / p) == (p / *v2)) << endl;
	cout << (*v2 != p) << endl;

	delete v2; //RECONSTRUCT WHAT

}