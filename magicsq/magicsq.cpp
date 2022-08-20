#include<bits/stdc++.h>

using namespace std;

int checkr(int cr, int n){
    if(cr<0){
        return n-1;
    }
    else
        return cr;
}

int checkc(int cc,int n){
    if(cc>n-1)
        return 0;
    else 
        return cc;
}

int main(){

    int n;
    cin>>n;
    cout<<endl;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=-1;
        }
    }
    int r=0,c;
    c=(n/2);
    int num=1,checker,vr,vc,cr,cc;
    cr=r; cc=c;
    int i=0;
    while(i<=(n*n)){
        checker=arr[cr][cc];
        if(checker==-1){
            vr=cr; vc=cc;
            arr[vr][vc]=num;
            ++num;
        }
        else{
            cr=vr; cc=vc;
            ++cr;
            arr[cr][cc]=num;
            ++num;
        }
        --cr;
        ++cc;
        cr=checkr(cr,n);
        cc=checkc(cc,n);
        i++;
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cout<<arr[i][j]<<" ";
       }
       cout<<endl;
    }
    return 0;
}