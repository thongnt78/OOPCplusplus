#include "bits/stdc++.h"
using namespace std;
class People
{
private:
    string name;
    int age;
    string job;
    string id;

public:
    People() {}
    People(string name, int age, string job, string id) : name(name), age(age), job(job), id(id) {}
    string getName() { return name; }
    int getAge() { return age; }
    string getJob() { return job; }
    string getId() { return id; }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Job: " << job << endl;
        cout << "Id: " << id << endl;
    }
};
class Family
{
private:
    string nameF;
    string status;
    string add;
    vector<People> p;

public:
    Family() {
        nameF=p[0].getName();
    }
    Family(string nameF, string status, string add, vector<People> p) : status(status), add(add), p(p) {
        nameF=p[0].getName();
    }
    string getStatus()
    {
        return status;
    }
    string getNameF() { return p[0].getName(); }
    string getAdd() { return add; }
    vector<People> getP() { return p; }
    void display()
    {
        cout << "householder's name: " << nameF << endl;
        cout << "Number Member: " << p.size() << endl;
        cout << "Address: " << add << endl;
        cout << "Status: " << status << endl;
        cout << "List Information Member" << endl;
        for (int i = 0; i < p.size(); i++)
        {
            p[i].display();
        }
    }
    static vector<Family> getPoorHousehold(vector<Family> fa)
    {
        vector<Family> v;
        for (int i = 0; i < fa.size(); i++)
        {
            if (fa[i].getStatus() == "Poor")
                v.push_back(fa[i]);
        }
        return v;
    }
    static vector<Family> findFamilySurename(vector<Family> fa, string surename)
    {
        vector<Family> v;
        for (int i = 0; i < fa.size(); i++)
        {
            if (fa[i].getNameF() == surename)
                v.push_back(fa[i]);
        }
        return v;
    }
};
class Group
{
private:
    string nameGr;
    vector<Family> f;

public:
    Group() {}
    Group(string name, vector<Family> f) : nameGr(name), f(f) {}
    vector<Family> getF() { return f; }
    void display(){
        cout<<"Name group "<<nameGr<<endl;
        for (int i = 0; i < f.size(); i++)
        {
          f[i].display();
        }
        
    }
    int getNumberFamily()
    {
        return f.size();
    }
    static double avgAgeGroup(Group v)
    {
        vector<Family> F(v.getF());
        int n = 0;
     double sum = 0;
        for (int i = 0; i < F.size(); i++)
        {
            vector<People> P(F[i].getP());
            for (int j = 0; j < P.size(); j++)
            {
                sum += P[i].getAge();
            }
            n+=P.size();
        }
        return sum / n;
    }
    static vector<People> getPeopleHaveNotJob(Group g)
    {
        vector<People> v;
        vector<Family> F(g.getF());
        for (int i = 0; i < F.size(); i++)
        {
            vector<People> P(F[i].getP());
            for (int j = 0; j < P.size(); i++)
            {
                if (P[j].getJob() == "")
                    v.push_back(P[j]);
            }
        }
        return v;
    }
};
int main() {
    People* a[4];  // tạo thông tin cho 4 người
    a[0] = new People("A", 20, "Dev", "1001");   // người thứ 1 có tên A,20t, Nghề: Dev , id : 1001
    a[1] = new People("B", 21, "Doctor", "1002"); // tương tự
    a[2] = new People("C", 10, "Unemplyed", "1003");
    a[3] = new People("D", 30, "Singer", "1004");
    vector<People*> p; // khởi tạo vector để luu thông tin của từng người
    for (auto x : a)
        p.push_back(x);
    for (auto x : p) { // xuất thông tin của từng người đó ra
        cout << "\t =======***=======\t\n";
        x->display();
        cout << "\n\t =======***=======\t\n";
    }
    // Tạo thông tin của ~ thành viên trong gia đình thứ nhất
    People x1("A1", 25, "Student", "1005");
    People y1("B1", 24, "Teacher", "1006");
    People z1("C1", 8, "Unemployed", "1007");
    People t1("D1", 35, "Dev", "1008");
    vector<People> p1;
    p1.push_back(x1);
    p1.push_back(y1);
    p1.push_back(z1);
    p1.push_back(t1);
    Family f1("Giadinh1", "poor", "Vinh Dien", p1);
    // Tạo thông tin của ~ thành viên trong gia đình  thứ hai
    People x2("A2", 25, "Unemployed", "1005");
    People y2("B2", 24, "Doctor", "1006");
    People z2("C2", 8, "Unemployed", "1007");
    People t2("D2", 35, "Singer", "1008");
    vector<People> p2;
    p2.push_back(x2);
    p2.push_back(y2);
    p2.push_back(z2);
    p2.push_back(t2);
    Family f2("Giadinh2", "poor", "Dien An", p2);
    // tạo vector chứa các thông tin của từng gia đình
    vector<Family> familys;
    familys.push_back(f1);
    familys.push_back(f2);
    for (auto x : familys) {  // test cho vui , xuất thông tin của từng gia đình đó ra
        cout << endl;
        x.display();
        cout << "\n\t =======***=======\t\n";
        return 0;
    }
}
