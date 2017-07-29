#include<iostream>
using namespace std;

void buildTree(int *a,int *tree,int index,int s,int e){
    ///Base Case
    if(s==e){
        tree[index] = a[s];
        return;
    }
    if(s>e){
        return;
    }

    ///Rec Case
    int mid = (s+e)/2;
    buildTree(a,tree,2*index,s,mid);
    buildTree(a,tree,2*index+1,mid+1,e);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}
int query(int *tree,int index,int s,int e,int qs,int qe){
    ///No Overlap
    if(s>qe || e<qs){
        return INT_MAX;
    }
    ///Complete Overlap
    if(s>=qs && e<=qe){
        return tree[index];
    }

    ///Partial Overlap
    int mid = (s+e)/2;
    int leftAns = query(tree,2*index,s,mid,qs,qe);
    int rightAns = query(tree,2*index+1,mid+1,e,qs,qe);
    return min(leftAns,rightAns);
}

void updateNode(int *tree,int index,int s,int e,int i,int inc){
    ///No Overlap
    if(i>e || i<s){
        return;
    }

    ///Base Case - Desired Node
    if(s==e){
        tree[index] += inc;
        return;
    }
    ///Otherwise take min of of left and right
    int mid = (s+e)/2;
    updateNode(tree,2*index,s,mid,i,inc);
    updateNode(tree,2*index+1,mid+1,e,i,inc);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

void updateRange(int *tree,int index,int s,int e,int rs,int re,int inc){
    ///No Overlap
    if(re< s|| rs>e){
        return;
    }

    ///Complete Overlap - Leaf node
    if(s==e){
        tree[index] += inc;
        return;
    }

    ///Partial
    int mid = (s+e)/2;
    updateRange(tree,2*index,s,mid,rs,re,inc);
    updateRange(tree,2*index+1,mid+1,e,rs,re,inc);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

int main(){
    int a[]= {1,3,0,2,4};
    int n = sizeof(a)/sizeof(int);

    int *tree = new int[4*n+1];

    buildTree(a,tree,1,0,n-1);

//    for(int i=1;i<10;i++){
//        cout<<tree[i]<<" ";
//    }

    int t;
    cin>>t;

    //updateNode(tree,1,0,n-1,1,-10);
    updateRange(tree,1,0,n-1,1,3,5);

    while(t--){
        int l,r;
        cin>>l>>r;

        cout<<query(tree,1,0,n-1,l,r)<<endl;
    }

return 0;
}
