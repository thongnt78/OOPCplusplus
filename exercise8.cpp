#include "bits/stdc++.h"
using namespace std;
class Food{
    private:
    string name;
    double price;
    public:
    Food(){}
    Food(string name,double price):name(name),price(price){}
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return name;
    }
    void setPrice(double price){
        this->price=price;
    }
    double getPrice(){
        return price;
    }
};
class CannedFood: public Food{
private:
int numberBox;
public:
CannedFood(){}
CannedFood(string name,double price,int numberBox):Food(name,price),numberBox(numberBox){}
void setNumberBox(int numberBox){
    this->numberBox=numberBox;
}
int getNumberBox(){
    return numberBox;
}
void display(){
    cout<<"Name: "<<Food::getName()<<endl;
    cout<<"Price: "<<Food::getPrice()<<endl;
    cout<<"Number Box: "<<numberBox<<endl;
}
static void sortNumberBox(vector<CannedFood>& vt){
    for (int i = 0; i < vt.size(); i++)
    {
        for (int j = i+1; j < vt.size(); j++)
        {
           if(vt[i].getNumberBox()>vt[j].getNumberBox())
           {
            swap(vt[i],vt[j]);
           }
        }
        
    }
}
};
class NonCFood: public Food{
    private:
    double weight;
    public:
    NonCFood(){}
    NonCFood(string name,double price,double weight):Food(name,price),weight(weight){}
    void display(){
          cout<<"Name: "<<Food::getName()<<endl;
    cout<<"Price: "<<Food::getPrice()<<endl;
    cout<<"Weight: "<<weight<<endl;
    }
    void setWeight(double weight){
        this->weight=weight;
    }
    double getWeight(){
        return weight;
    }
    static void sortWeight(vector<NonCFood> &vt){
        for (int i = 0; i < vt.size(); i++)
    {
        for (int j = i+1; j < vt.size(); j++)
        {
           if(vt[i].getWeight()>vt[j].getWeight())
           {
            swap(vt[i],vt[j]);
           }
        }
    }
    }
};
int main()
{
    vector<CannedFood>cf;

    cf.push_back(CannedFood("Fish", 500, 3));
    cf.push_back(CannedFood("Meat", 500, 2));
    cf.push_back(CannedFood("Egg", 500, 1));

    CannedFood::sortNumberBox(cf);


    vector<NonCFood>ncf;

    ncf.push_back(NonCFood("Fish", 500, 60));
    ncf.push_back(NonCFood("Meat", 500, 40));
    ncf.push_back(NonCFood("Egg", 500, 20));

    NonCFood::sortWeight(ncf);
    
   

    cout << endl;
  return 0;
}
