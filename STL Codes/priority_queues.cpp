#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<cstring>
using namespace std;

class Book{
public:
    string name;
    int price;

    Book(){
    }
    Book(string n,int p){
        name = n;
        price = p;
    }
    void print(){
        cout<<name<<endl;
        cout<<price<<endl<<endl;
    }

};

class bookCompare{
public:
    bool operator()(Book b1,Book b2){
        //cout<<"Comparing 2 books "<<b1.name<<" and "<<b2.name<<endl;

        return b1.price < b2.price;
    }

};

int main(){

    priority_queue<int,vector<int>, greater<int> > pq;

    int a[10] = {1,4,3,0,8,7};

    for(int i=0;i<6;i++){
        pq.push(a[i]);
    }

    while(!pq.empty()){
        int topElement = pq.top();
        cout<<topElement<<" ";
        pq.pop();
    }

    Book b1("C++",100);
    Book b2("Java",200);
    Book b3("Python",170);

    priority_queue<Book, vector<Book>, bookCompare > pb;
    //bookCompare cmp;

    pb.push(b1);
    pb.push(b2);
    pb.push(b3);

    while(!pb.empty()){
        Book topBook = pb.top();
        topBook.print();
        pb.pop();
    }



return 0;
}
