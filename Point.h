/**
 * @file Point.h
 * @brief Point Header file containing the Point class.
 */
#ifndef POINT_H
#define POINT_H
#include<string>
#include<iostream>
#include<stdexcept>
#include<cmath>

/**
 *  @class Point
 *  @brief A Point class. Its use for members of Kmean class vectors. Also capable for some calculations 
 *  like finding distance , getting number of points and setting points by using operator overloading
 *
 */

using namespace std;

/**
* @brief PointValues struct for istream proccess .
* @param value point id , X and Y coordinates.
*/
struct PointValues {


	int ID;
	double x;
	double y;

};
class Point
{
	/**
* @brief ostream overload function for Point to print.
* @return returns ostream.
*/
	friend ostream& operator << (ostream& out, const Point& p);
	
	
	/**
* @brief istream overload function for Point.
* This function uses PointValues struct to fill datamembers.
* @return returns istream.
*/
	friend istream& operator >> (istream& in, Point& p);

public:
	/**
 * @brief Constructor function for Point.
 * @param value point id , X and Y coordinates.
 */
	Point(int = 0, double = 0.0, double = 0.0);



/**
 * @brief setXcoor function for Point.
 * @param value point  X .
 */
	void setXcoor(double);



	/**
	 * @brief setYcoor function for Point.
	 * @param value point  Y .
	 */
	void setYcoor(double);



	/**
	 * @brief setID function for Point.
	 * @param value point OF ID .
	 */
	void setID(int);



	/**
	 * @brief getXcoor function for Point.
	 * @return coordinates of X
	 */
	double getXcoor(void)const;



	/**
	 * @brief getYcoor function for Point.
	 * @return coordinates of Y
	 */
	double getYcoor(void)const;



	/**
	 * @brief getID function for Point.
	 * @return coordinates of ID
	 */
	int getID(void)const;



	/**
	 * @brief print function for Point.
	 * @return Printing Point ID, X ,Y values on consol.
	 */
	void print(void)const;



	/**
 * @brief operator overload function for Point.
 * @returns Points that filled with arguments
 */

	Point& operator<(const PointValues& values);




	/**
 * @brief distance function for Point.
 * @returns The distance value between the point calling this function and the point sent to the function.
 */
	double distance(Point& a);


	/**
* @brief static int getCount function for Point.
* @return Number of Point created objects.
*/
	static int getCount(void);

	
	/**
	 * @brief Destructor method for Point.
	 */
	~Point();
private:
	double Xcoor;
	double Ycoor;
	int ID;
	static int count;

};

#endif
