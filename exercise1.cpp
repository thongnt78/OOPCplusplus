#include "bits/stdc++.h"
using namespace std;
class Card{
    private:
    string nameBook;
    string nameAuthor;
    int numberBook;
    public:
    Card(){

    }
    Card(string nameBook,string nameAuthor,int numberBook):nameBook(nameBook),nameAuthor(nameAuthor),numberBook(numberBook){}
    void display(){
        cout<<"Name Book: "<<nameBook<<endl;
        cout<<"Name Author: "<<nameAuthor<<endl;
        cout<<"Number Book: "<<numberBook<<endl;
    }
    int getNumBook(){
        return numberBook;
    }
    static void sortCard(vector<Card> &cards){
        for (int i = 0; i < cards.size()-1; i++)
        {
            for (int j = i+1; j < cards.size(); j++)
            {
                if (cards[i].getNumBook()>cards[j].getNumBook())
                swap(cards[i],cards[j]);
            }
            
        }
        
    }

};