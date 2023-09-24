#include "bits/stdc++.h"
using namespace std;
class Point{
    private:
    int x,y;
    public:
    Point(){}
    Point(int x,int y):x(x),y(y){}
      int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    friend Point operator - (Point A,Point B){
        return Point(A.x-B.x,A.y-B.y);
    }
    double distance(Point B){
        return sqrt((this->x-B.x)*(this->x-B.x)+(this->y-B.y)*(this->y-B.y));
    }
    void display(){
      	cout << "X = " << x << " Y = " << y << endl;
    }
};
class Triangle: public Point{
    private:
    Point A,B,C;
    public:
    Triangle(){}
    Triangle(Point A,Point B,Point C): A(A),B(B),C(C){}
    void setA(Point A)
	{
		this->A = A;
	}
	Point getA()
	{
		return A;
	}
	void setB(Point B)
	{
		this->B = B;
	}
	Point getB()
	{
		return B;
	}
	void setC(Point C)
	{
		this->C = C;
	}
	Point getC()
	{
		return C;
	}
    double perimeter(){
        return A.distance(B)+A.distance(C)+B.distance(C);
    }
    double area(){
        double ab=A.distance(B);
        double ac=A.distance(C);
        double bc=B.distance(C);
        double p=(ab+ac+bc)/2;
        return sqrt(abs(p*(p-ab)+(p-ac)*(p-bc)));
    }
    Point center(){
       return Point((A.getX()+B.getX()+C.getX())/3,(A.getY()+B.getY()+C.getY())/3);
    }
      bool Triangle_Check(){
        double a=A.distance(B);
        double b=A.distance(C);
        double c=B.distance(C);
        if(a+b>0&&a+c>0&b+c>0&&a>0&&b>0&&c>0)return true;
        return false;
      }
};
int main()
{
    
    Point A(1,2);  // kết quả có thể ra khác nhau tùy vào cách viết hàm ở 2 lớp Point, Triangle
    Point B(4,5);
    Point C = B - A;
    C.display();


    Triangle tri(Point(1,2), Point(4,5), Point(6,7)); 

    cout << "Perimeter: " << tri.perimeter() << endl;  
    cout << "Area: " << tri.area() << endl;


    tri.center().display(); // tri.center() trả về điểm có tọa độ trọng tâm, có hoành độ x, tung độ y
                            // Point G = tri.center(); tạo ra G và gán tri.center() cho G
                            // G.display()    sau đó gọi hàm display() , đây là cách viết khác

    Point(5,5).display(); // in ra x = 5, y = 5

    cout << tri.Triangle_Check(); // nếu là false in ra 0, true in ra 1

    cout << endl;
    system("pause");
}