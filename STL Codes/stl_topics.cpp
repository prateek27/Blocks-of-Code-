#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int a,int b){
    return a>b;
}
#define fruit pair<string,int>

bool fruitCompare(fruit f1,fruit f2){
    return f1.second > f2.second;
}

int main(){

    int a[] = {5,4,1,2,3};
    int  n = 5;

    sort(a,a+n,compare);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    fruit p1("mango",100);
    fruit p2("apple",200);
    fruit p3("guava",50);

    vector<fruit>  vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    sort(vp.begin(),vp.end(),fruitCompare);

    for(int i=0;i<vp.size();i++){

        cout<<vp[i].first<<endl;
        cout<<vp[i].second<<endl<<endl;
    }
    /// binarySearch, upperBound, lowerBound, sort, search


return 0;
}
