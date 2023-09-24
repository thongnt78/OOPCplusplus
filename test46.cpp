#include "iostream"
#include "vector"
using namespace std;
class Author{
    private:
    string name;
    string email;
    public:
    Author(string name,string email){
        this->name=name;
        this->email=email;
    }
    void setName(string name){
        this->name=name;
    }    
    string getName(){
        return name;
    }
    void setEmail(string email){
        this->email=email;
    }
    string getEmail(){
        return email;
    }
};
class Book{
    private:
    string name;
    vector<Author> authors;
    double price;
    public:
    Book(string name,vector<Author> authors,double price){
        this->name=name;
        this->authors=authors;
        this->price=price;
    }
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
    string getAuthorNames(){
        string authorNames="";
        for (int i = 0; i < authors.size()-1;i++){
            authorNames+=authors[i].getName()+", ";
        }
       authorNames+=authors[authors.size()-1].getName();
        return authorNames;
    }
};
int main() {
	vector<Author> authors;
	authors.push_back(Author("Viet", "VietCV@codelearn.io"));
	authors.push_back(Author("Tuan", "TuanLQ7@codelearn.io"));
	authors.push_back(Author("Kien", "KienNT@codelearn.io"));
	Book book1("C++ for Beginners", authors, 210000);
	cout << book1.getAuthorNames();	
	return 0;
}
