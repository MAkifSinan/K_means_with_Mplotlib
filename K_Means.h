/**
 * @file K_Means.h
 * @brief K_Means Header file containing the K_Means class.
 */
#pragma once
#ifndef K_MEANS_H
#define K_MEANS_H
#include"Point.h"
#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "matplotlibcpp.h"
#include <algorithm>
 /**
  *  @class K_Means
  *  @brief A class that clustering class that 
  *   clusters given points
  * 
  */



using namespace std;
namespace plt = matplotlibcpp;

using PointPair = pair<int, Point>;

class K_Means
{

public:
	/**
* @brief Constructor function for K_Means.
* @param value points datas file name  and requested 
* cluster number.
*/
	K_Means(string,int);

	/**
* @brief setFileName function for K_Means.
* @param value points datas file name .
*/
	void setFileName(string);

	/**
* @brief getFileName function for K_Means.
* @return datas file name .
*/
	string getFileName(void)const;

	/**
* @brief setKnumber function for K_Means.
* @param integer value for setting number of Clusters .
*/
	void setKnumber(int);

	/**
* @brief getKnumber function for K_Means.
* @return integer value for getting number of Clusters .
*/
	int getKnumber(void)const;

	/**
* @brief getPointVector function for K_Means.
* @return vector<PointPair> type vector that holding points .
*/

	vector<PointPair> getPointVector() const;


	/**
* @brief displayBeforeKmeans function for K_Means.
*  This function prints points on console by using STL algoritm and point class'
*  operator overloaded function.
*/

	void displayBeforeKmeans()const;


	/**
* @brief addPoint function for K_Means. This function fills points into to point vector.
* @param Integer Point id and Point type point.
*/

	void addPoint(int id, const Point& point);

/**
* @brief initializeCentroids  function for K_Means. This function start 
* centorid by choosing them randomly from Points vector
* 
* @param Integer number of clusters.
*/

	void initializeCentroids(int k);

/**
* @brief assignPointsToClusters function for K_Means. This function
* calls  " findClosestCentroid  " functions for every point sample.
*
*/
	void assignPointsToClusters();

/**
* @brief findClosestCentroid function for K_Means. This function
* assings Points to cluster by using Point class distance function.
*/
	int findClosestCentroid(Point& point);

/**
* @brief run function for K_Means. This function clusters points. It calls   "updateCentroids",	"assignPointsToClusters" and 
* "displayBeforeKmeans" functions are called as many times as the number of iterations. 
* @param Integer iterations numbers . Its shown as data member as "K" value.
*/

	void run(int);

/**
* @brief updateCentroids function for K_Means. This function updates clusters to reorganize clusters centers.
*/
	void updateCentroids(void);
/**
* @brief showPointsOnGraph function for K_Means. This function uses matplotlibcpp.h class to display points on graph.
*/
	void showPointsOnGraph()const ;
/**
* @brief K_Means Destructor for K_Means.
*/
	~K_Means();
private:
	string fileName;
	int K;
	vector<Point> centroids;
	vector<PointPair> pointVector;
	void setPointVector(void);
	void printPointPair(const PointPair& pointPair) const;
};

#endif
