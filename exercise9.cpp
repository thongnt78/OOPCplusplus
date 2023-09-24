#include "bits/stdc++.h"
using namespace std;
class Score{
    protected:
    double math,literature,english;
    public:
    Score(){}
    Score(double math,double literature,double english):math(math),literature(literature),english(english){}
    double getMath(){return math;}
    double getLiterature(){return literature;}
    double getEnglish(){return english;}
    virtual double pointA(){return 0;}
    virtual double pointB(){return 0;}
    virtual double pointC(){return 0;}
    virtual double pointD(){return math+literature+english;}
    virtual double avgPoint()=0;
    virtual void display()   
	{
		cout << "Avg = " << avgPoint() << endl;
	}
    static double getMaxAvg(vector<Score*> vt){
        int max=vt[0]->avgPoint();
        for (int i = 0; i < vt.size(); i++)
        {
            if(vt[i]->avgPoint()>max)
            max=vt[i]->avgPoint();
        }
        return max;
    }
    static double getMinAvg(vector<Score*> vt){
        int min=vt[0]->avgPoint();
        for (int i = 0; i < vt.size(); i++)
        {
            if(vt[i]->avgPoint()<min)
            min=vt[i]->avgPoint();
        }
        return min;
    }
    bool isPass(){
        if(avgPoint()>5)return true;
        return false;
    }
    static double getMaxPointA(vector<Score*> vt){
        double max=vt[0]->pointA();
        for (int i = 1; i < vt.size(); i++)
        {
            if(vt[i]->pointA()>max)
            max=vt[i]->pointA();
        }
        return max;
    }
     static double getMaxPointB(vector<Score*> vt){
        double max=vt[0]->pointB();
        for (int i = 1; i < vt.size(); i++)
        {
            if(vt[i]->pointB()>max)
            max=vt[i]->pointB();
        }
        return max;
    }
     static double getMaxPointC(vector<Score*> vt){
        double max=vt[0]->pointC();
        for (int i = 1; i < vt.size(); i++)
        {
            if(vt[i]->pointC()>max)
            max=vt[i]->pointC();
        }
        return max;
    }
    static double getMaxPointD(vector<Score*> vt){
        double max=vt[0]->pointA();
        for (int i = 1; i < vt.size(); i++)
        {
            if(vt[i]->pointD()>max)
            max=vt[i]->pointD();
        }
        return max;
    } 
};
class ScoreNatural:public Score{
    private:
    double physic,chemistry,biology;
    public:
   ScoreNatural() {}
    ScoreNatural(double math, double literature, double english, double physic, double chemistry, double biology)
        :Score(math, literature, english), physic(physic), chemistry(chemistry), biology(biology) {}
    double getPhysic() { return physic;}
    double getChemistry(){ return chemistry;}
    double getBiology() {  return biology; }
    double pointA() { return math + chemistry + physic; }
    double pointB(){return math + chemistry + biology;}
    double pointNatual() {return physic + chemistry + biology; }
    double avgPoint(){ return (physic + chemistry + biology + math + literature + english) / 6; }
};
class ScoreSocial:public Score{
    private:
    double ce,geography,history;
    public:
    ScoreSocial(){}
    ScoreSocial(double math, double literature, double english, double ce, double geography, double history) :
		Score(math, literature, english), ce(ce), geography(geography), history(history) {}
    double getCe(){return ce;}
    double getGeography(){ return geography;}
    double getHistory(){ return history;}
    double pointC(){return math+literature+english;}
    double pointSocial(){return ce+geography+history;}
    double avgPoint(){return (math+literature+english+ce+geography+history)/6;}
};
int main()
{
    Score *s[6];

    s[0] = new ScoreNatural(5,5,5,5,5,5);
    s[1] = new ScoreSocial(4,4,4,4,4,4);
    s[2] = new ScoreNatural(6,6,6,6,6,6);
    s[3] = new ScoreSocial(7,7,7,7,7,7);
    s[4] = new ScoreNatural(8,8,8,8,8,8);
    s[5] = new ScoreSocial(9,9,9,9,9,9);

    for(int i=0;i<6;i++) // lớp Natural không có pointC(), pointD() nên trả về 0, lớp kia cũng tương tự
    {
        cout << "Point A: " << s[i]->pointA() << endl;
        cout << "Point B:" << s[i]->pointB() << endl;
        cout << "Point C:" << s[i]->pointC() << endl;
        cout << "Point D:" << s[i]->pointD() << endl;
        cout << "______________________________" << endl;
    }
}
