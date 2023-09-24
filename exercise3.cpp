#include "bits/stdc++.h"
using namespace std;
class Subject{
    private:
    string nameSub;
    double point;
    int numberCredit;
    long money;
    public:
    Subject(){}
    Subject(string nameSub,double point,int numberCredit,long money):nameSub(nameSub),point(point),numberCredit(numberCredit),money(money){}
    string getNameSub(){
        return nameSub;
    }
    double getPoint(){
        return point;
    }
    int getNumberCredit(){
        return numberCredit;
    }
    long getMoney(){
        return money;
    }
    void display(){
        cout<<"Name Subject: "<<nameSub<<endl;
        cout<<"Point: "<<point<<endl;
        cout<<"Number Credit: "<<numberCredit<<endl;
        cout<<"Money Of One Credit: "<<money<<endl;
    }
};
class Student{
    private:
    string id;
    string name;
    vector<Subject> s;
    public:
    Student() {}
	Student(string id, string name, vector<Subject> s) : id(id), name(name), s(s) {}
	string getId()
	{
		return id;
	}
	string getName()
	{
		return name;
	}
	vector<Subject> getS()
	{
		return s;
	}
    long getSumMoney(){
        int sum=0;
        for (int i = 0; i < s.size(); i++)
        {
            sum+=s[i].getNumberCredit() * s[i].getMoney();
        }
        return sum;
    }
    double avgPoint(){
        double point=0;
        int sum=0;
        for (int i = 0; i < s.size(); i++)
        {
           sum+=s[i].getNumberCredit();
            point+=s[i].getPoint()*s[i].getNumberCredit();
        }
       return point/sum; 
    }
    void display(){
        cout << "Id: " << id << endl;
		cout << "Name Student: " << name << endl;
		cout << "List Subject" << endl;
        for (int i = 0; i < s.size(); i++)
        {
            s[i].display();
        }
        cout << "Sum Money Have To Pay: " << getSumMoney() << endl;
		cout << "Average Point: " << avgPoint() << endl;
    }
    
};
