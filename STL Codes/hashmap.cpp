#include<iostream>
#include<unordered_map>
using namespace std;



int main(){

    unordered_map<string, int>  m;

    m["apple"] = 100;

    m.insert(make_pair("mango",200));

    string f;
    cin>>f;

    if(m.count(f)){
        cout<<"price of "<<f<<" is "<<m[f]<<endl;
    }
    else{
        cout<<"Fruit doesn't exist !"<<endl;
    }

    m.erase(f);

    auto searchFruit = m.find(f);
    if(searchFruit==m.end()){
        cout<<"Nahin mila "<<endl;
    }
    m.clear();





return 0;
}
