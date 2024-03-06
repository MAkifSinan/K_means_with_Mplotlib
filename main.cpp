
#include <iostream>
#include"Point.h"
#include<stdexcept>
#include"K_Means.h"
#include <iostream>
#include "matplotlibcpp.h"
#include <vector>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
namespace plt = matplotlibcpp;
int main(int argc, char** argv) {
	try {

	string filename = "40.txt";

	K_Means kMean(filename,5);

	kMean.displayBeforeKmeans();

	kMean.run(1);
	kMean.showPointsOnGraph();


	}
	catch (invalid_argument &e)
	{
		cout << e.what() << endl;
	}
	


	return 0;

}
