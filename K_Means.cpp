#include "K_Means.h"

K_Means::K_Means(string a,int k) :fileName(a)
{
    setPointVector();
    setKnumber(k);
    initializeCentroids(getKnumber());
    assignPointsToClusters();

}
void K_Means::setKnumber(int a) {
    if (a>getPointVector().size()) {
        throw invalid_argument(" k number can NOT greater than total point number");
    }
    K = a;
}
int K_Means::getKnumber(void)const {
    return K;
}
string K_Means::getFileName(void) const
{
    return fileName;
}
void K_Means::initializeCentroids(int k) {
    centroids.clear();
    srand(100000);  // Seed 
    vector<PointPair> pointVector_copy;
    pointVector_copy = pointVector;
    for (int i = 0; i < k; ++i) {
        int randomIndex = rand() % pointVector_copy.size();
        centroids.push_back(pointVector_copy[randomIndex].second);
        pointVector_copy.erase(pointVector_copy.begin() + randomIndex);
    }
    for (int i = 0; i < centroids.size(); i++)
        cout << "centroids: " << centroids[i];

}

void K_Means::assignPointsToClusters() {
    for (int i = 0; i < pointVector.size(); ++i) {
        int closestCentroidIndex = findClosestCentroid(pointVector[i].second);
        pointVector[i].first = closestCentroidIndex;  
    }
}
// id , point pair UNUTMA

int K_Means::findClosestCentroid(Point& point) {
    double minDistance = numeric_limits<double>::max();
    int closestCentroidIndex = -1;

    for (int i = 0; i < centroids.size(); ++i) {
        double distance = point.distance(centroids[i]);
        if (distance < minDistance) {
            minDistance = distance;
            closestCentroidIndex = i;
        }
    }
    return closestCentroidIndex;
}




void K_Means::setPointVector(void) {
    std::ifstream file(getFileName());

    if (file.is_open()) {
        double x, y;
        int i = 1;
        while (file >> x >> y) {
            Point point(i, x, y);
            addPoint(0, point);
            i++;
        }
        cout << "opening file: " << getFileName() << std::endl;

        file.close();
    }
    else {
        throw invalid_argument(" Error :: file could NOT open");
       
    }
}


void K_Means::addPoint(int id, const Point& point) {
    pointVector.push_back(make_pair(id, point));
}

void K_Means::displayBeforeKmeans() const {

    std::for_each(pointVector.begin(), pointVector.end(), [this](const PointPair& pointPair) {
        printPointPair(pointPair);
        });

}


void K_Means::printPointPair(const PointPair& pointPair) const {
    std::cout << "Cluster ID: " << pointPair.first << ", " << pointPair.second;

}

void K_Means::run(int maxIterations) {
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        //assignPointsToClusters();
        updateCentroids();
        assignPointsToClusters();
        displayBeforeKmeans();
        //showPointsOnGraph();

    }
}

void K_Means::updateCentroids(void) {
    
    double new_centroid_x = 0.0;
    double new_centroid_y = 0.0;
    int j = 0;
    int centroid_size = centroids.size();
    std::cout << "centroids size " << centroid_size << endl;

    centroids.clear();
    for (int i = 0; i < centroid_size; i++) {
        // i centroid id si oluyor böylece
        for (vector<PointPair>::const_iterator it = pointVector.begin(); it != pointVector.end(); ++it) {
            if (i == it->first) {
                new_centroid_x+= it->second.getXcoor();
                new_centroid_y+= it->second.getYcoor();
                j++;

                //std::cout << " cluster id = " << i << " it-< second point id = " << it->second.getID() << endl;

            }
           // std::cout << "************************************************************** " << i << endl;
        }
        Point centroid;
        centroid.setXcoor(double(new_centroid_x / j));
        centroid.setYcoor(double(new_centroid_y / j));
        centroid.setID(int(i));
        cout << " new centroid is : " << centroid;
        centroids.push_back(centroid);
        centroid.~Point();
      //  std::cout << "centroids size after fill " << centroid_size << endl; sürekli 5 gelecek 
    }
}
void K_Means::showPointsOnGraph() const {
   

    std::vector<double> x, y;
    std::vector<double> centroid_x, centroid_y;

    for (vector<Point>::const_iterator it = centroids.begin(); it != centroids.end(); ++it) {
        it->print();
        centroid_x.push_back(it->getXcoor());
        centroid_y.push_back(it->getYcoor());
    }
    std::cout << "k is :" << K << endl;

    for (int i = 0; i < K; i++) {

        for (vector<PointPair>::const_iterator it = pointVector.begin(); it != pointVector.end(); ++it) {
            if (i == it->first) {
                x.push_back(it->second.getXcoor());
                y.push_back(it->second.getYcoor());
                //std::cout << " cluster id = " << i << " it-< first int = "<< it->first << endl;

            }
        }
        plt::scatter(centroid_x, centroid_y, 50.0, { {"marker", "*"}});
        plt::scatter(x, y, 50);
        x.clear();
        y.clear();
    }
    plt::show();
}

vector<PointPair> K_Means::getPointVector() const {
    return pointVector;

}

K_Means::~K_Means()
{
}
