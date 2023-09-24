#include "bits/stdc++.h"
using namespace std;
class Person{
    private:
    string name;
    int age;
    string add;
    string tel;
    string sex;
    public:
    Person(){}
    Person(string name,int age,string add,string tel,string sex):name(name),age(age),add(add),tel(tel),sex(sex){}
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
   string getAdd(){
    return add;
   }
    string getTel(){
       return tel;
    }
    string getSex(){
        return sex;
    }
    virtual void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Sex: "<<sex<<endl;
        cout<<"Add: "<<add<<endl;
        cout<<"Tel: "<<tel<<endl;
    }
    virtual long salary()=0;
    static vector<Person*> findPerson(vector<Person*> p ){
        vector<Person*> v;
        for (int i = 0; i < p.size(); i++)
        {
            if(p[i]->add=="HN")
            v.push_back(p[i]);
        }
        return v;
    }
};
class EmployeePT:public Person{
    private:
    int hour;
    long money;
    public:
    EmployeePT(){}
    EmployeePT(string name,int age,string add,string tel,string sex,int hour,long money):Person(name,age,add,tel,sex),hour(hour),money(money){}
    int getHour(){
        return hour;
    }
    long getMoney(){
        return money;
    }
    long salary(){
        return hour*money;
    }
   virtual void display(){
        cout<<"Employee Part Time"<<endl;
        Person::display();
        cout<<"Hour: "<<hour<<endl;
        cout<<"Money: "<<money<<endl;
        cout<<"Salary: "<<salary()<<endl;
    }
  static  vector<EmployeePT> getMaxSalary(vector<EmployeePT> pt){
        int Max=pt[0].salary();
        for (int i = 0; i < pt.size(); i++)
        {
          if(pt[i].salary()>Max)
          Max=pt[i].salary();
        }
         vector<EmployeePT> v;
        for (int i = 0; i < pt.size(); i++)
        {
         if(pt[i].salary()==Max)
         v.push_back(pt[i]);
        }
        return v;
    }
};
class EmployeeFT: public Person{
    private:
    int day;
    long money;
    public:
    EmployeeFT(){}
    EmployeeFT(string name,int age,string add,string tel,string sex,int day,long money):Person(name,age,add,tel,sex),day(day),money(money){}
    int getDay(){
        return day;
    }
    long getMoney(){
        return money;
    }
    long salary(){
        return day*money;
    }
    void display(){
        cout<<"Employee Full Time"<<endl;
        Person::display();
        cout<<"Day: "<<day<<endl;
        cout<<"Money: "<<money<<endl;
        cout<<"Salary: "<<salary()<<endl;
    }
   static vector<EmployeeFT> getMaxSalary(vector<EmployeeFT> ft){
        int Max=ft[0].salary();
        for (int i = 0; i < ft.size(); i++)
        {
            if(ft[i].salary()>Max)
            Max=ft[i].salary();
        }
        vector<EmployeeFT> v;
        for (int i = 0; i < ft.size(); i++)
        {
            if(ft[i].salary()==Max)
            v.push_back(ft[i]);
        }
        return v;
    }
};
