#include<iostream>
#include<set>
using namespace std;


int main(){


    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(0);
    s.insert(3);
    s.insert(2);
    s.insert(3);

    s.erase(0);
    auto f = s.find(5);
    if(f==s.end()){
        cout<<"5 doesn't exist"<<endl;
    }
    for(auto it=s.begin();it!=s.end();it++){
            cout<< *it <<endl;

    }
    for(auto j:s){
            cout<<j <<" ";
    }





}
