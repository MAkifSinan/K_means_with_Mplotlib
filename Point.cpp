#include "Point.h"
int Point::count = 0;

int Point::getCount(void) {
	return count;
}

Point::Point(int c, double a, double b)
{
	setXcoor(a);
	setYcoor(b);
	setID(c);
	//cout<< "Constructor of Point Class  " << endl;
	count++;
}

Point::~Point()
{

	//cout<< "Destructor of Point Class  " << endl;
	count--;
}

void Point::setXcoor(double a) {
	Xcoor = a;
}

void Point::setYcoor(double a) {
	Ycoor = a;
}

void Point::setID(int a) {
	if (a < 0) {
		throw invalid_argument(" id number can NOT be negative");
	}
	else
		ID = a;
}

double Point::getXcoor(void)const {
	return Xcoor;
}

double Point::getYcoor(void)const {
	return Ycoor;
}

int Point::getID(void)const {
	return ID;
}

void Point::print(void)const {
	cout << getID() << "(" << getXcoor() << "," << getYcoor() << ")" << endl;
}

double Point::distance(Point& a) {
	return sqrt(pow(a.getXcoor() - getXcoor(), 2) + pow(a.getYcoor() - getYcoor(), 2));
}

Point& Point::operator<(const PointValues& values) {
	Xcoor = values.x;
	Ycoor = values.y;
	ID = values.ID;
	return *this;
}

ostream& operator << (ostream& out, const Point& p)
{
	out << p.getID() << "(" << p.getXcoor() << "," << p.getYcoor() << ")" << endl;
	return out;
}

istream& operator >> (istream& in, Point& p)
{
	int p_id;
	double p_x;
	double p_y;

	cout << "Enter Point ID " << endl;
	in >> p_id;
	p.setID(p_id);

	cout << "Enter Points X " << endl;
	in >> p_x;
	p.setXcoor(p_x);

	cout << "Enter Points Y " << endl;
	in >> p_y;
	p.setYcoor(p_y);
	return in;
}
