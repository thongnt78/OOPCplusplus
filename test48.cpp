#include "bits/stdc++.h"
using namespace std;
class Point{
    private:
    int x;
    int y;
    public:
    Point(){
    }
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
    int getX(){
        return x;
    }
    void setX(int x){
        this->x=x;
    }
    int getY(){
        return y;
    }
    void setY(int y){
        this->y=y;
    }
};
class PolyLine{
    private:
    vector<Point> points;
    public:
    PolyLine(){

    }
    PolyLine(vector<Point> points){
        this->points=points;
    }
    void appendPoint(Point point){
        points.push_back(point);
    }
    //hai cái này đều có kết quả giống nhau.
    void appendPoint(int x,int y){
        points.push_back(Point(x,y));
    }
    double getLength(){
        double length=0;
        for (int i = 0; i < points.size()-1; i++)
        {
            int x1=points[i].getX();
            int y1=points[i].getY();
            int x2=points[i+1].getX();
            int y2=points[i+1].getY();
           double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
           length+=distance;
        }
        return length;
    }
};

int main() {
	PolyLine polyLine;
	// polyLine.appendPoint(Point(1, 1));
	// polyLine.appendPoint(Point(2, 3));
    polyLine.appendPoint(1, 1);
	polyLine.appendPoint(2, 3);
	polyLine.appendPoint(3, 0);
	polyLine.appendPoint(4, 2);
	cout << polyLine.getLength();
	return 0;
}