#include "bits/stdc++.h"
using namespace std;
class Transport{
    private:
    string manufacturer;
    string name;
    int speed;
    int year;
    public:
    Transport(){}
    Transport(string manufacturer,string name,int year,int speed ):manufacturer(manufacturer),name(name),year(year),speed(speed){}
    string getManufacturer(){
        return manufacturer;
    }
    string getName(){
        return name;
    }
    int getYear(){
        return year;
    }
    int getSpeed(){
        return speed;
    }
    void display(){
        cout<<"Manufactorer: "<<manufacturer<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Year Of Manufacturer: "<<year<<endl;
        cout<<"Speed: "<<speed<<endl;
    }
};
class Car: public Transport{
    private:
    int numberSeat;
    string engineType;
    public:
    Car(){}
    Car(string manufacturer,string name,int year,int speed,int numberSeat,string engineType):Transport(manufacturer,name,year,speed),numberSeat(numberSeat),engineType(engineType){}
   int getNumberSeat(){
        return numberSeat;
    }
    string getEngineType(){
        return engineType;
    } 
    double getSpeedBasic(){
        return getSpeed()/getNumberSeat();
    }
    void display(){
         Transport::display();
        cout<<"Number Seat: "<<numberSeat<<endl;
        cout<<"Engine Type: "<<engineType<<endl;
        cout<<"Speed Basic: "<<getSpeedBasic()<<endl;
    }
    static vector<Car> getCarHaveMaxSpeedBasic(vector<Car> vt){
        vector<Car> v;
        double max=vt[0].getSpeedBasic();
        for (int i = 0; i < vt.size(); i++)
        {
          if(vt[i].getSpeedBasic()<max)
          max=vt[i].getSpeedBasic();
        }
        for (int i = 0; i < vt.size(); i++)
        {
            if(vt[i].getSpeedBasic()==max)
            v.push_back(vt[i]);
        }
        return v;
    }
    static vector<Car> getCarHaveMaxSeat(vector<Car> vt){
        vector<Car> v;
        double max=vt[0].getNumberSeat();
        for (int i = 0; i < vt.size(); i++)
        {
            if(vt[i].getNumberSeat()>max)
            max=vt[i].getNumberSeat();
        }
        for (int i = 0; i < vt.size(); i++)
        {
            if(vt[i].getNumberSeat()==max)
            v.push_back(vt[i]);
        }
        return v;
    }
};
int main(){
    vector<Car> vt;
    Car c1("VietNam", "VinFast", 2021, 300, 4, "diesel");
    Car c2("Japan", "Toyota", 2022, 280, 4, "petrol");
    Car c3("Korea", "Huyndai", 2023, 350, 4, "diesel");
    vt.push_back(c1);
    vt.push_back(c2);
    vt.push_back(c3);
    for (int i = 0; i < vt.size(); i++)
    {
        vt[i].display();
        cout << "---------------------" << endl;
    }
    vector<Car> v = Car::getCarHaveMaxSpeedBasic(vt);
    for (int i = 0; i < v.size(); i++)
    {
        cout << "---------MAX-SPEED----------" << endl;
        v[0].display();
        
    }
    
}