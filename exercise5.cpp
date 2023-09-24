#include "bits/stdc++.h"
using namespace std;
class Geometry{
    public:
    virtual double perimeter()=0;
    virtual double area()=0;
    virtual void display(){
        cout<<"Perimeter: "<<perimeter()<<endl;
        cout<<"Area: "<<area()<<endl;
    }
};
class Traingle:public Geometry{
    private:
    int a;
    int b;
    int c;
    public:
    Traingle(){}
    Traingle(int a,int b,int c):a(a),b(b),c(c){}
    double perimeter(){
        return a+b+c;
    }
    double area(){
        double p=(a+b+c)/2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

};
class Circle:public Geometry{
    private:
    int r;
    public:
    Circle(){}
    Circle(int r):r(r){}
    double perimeter(){
        return 2*3.14*r;
    }
     double area(){
        return 3.14*r*r;
    }
};
class Retangle:public Geometry{
    private:
    int h;
    int w;
    public:
    Retangle(){}
    Retangle(int h,int w):h(h),w(w){}
    double perimeter(){
        return (h+w)*2;
    }
    double area(){
        return h*w;
    }
};
int main()
{
    Geometry **geometry = new Geometry *[4];
    geometry[0] = new Traingle(3, 4, 5);
    geometry[1]=new Retangle(3,5);
    geometry[2]=new Circle(2);
    geometry[3]=new Circle(3);
    for (int i = 0; i < 4; i++)
    {
       geometry[i]->display();
    }
}