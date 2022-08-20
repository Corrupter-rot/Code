#include<iostream>
#include<vector>

using namespace std;

int getmax(vector<int> keyboards,vector<int> drives,int b){
    int prices=0;
    for(int i : keyboards){
        for(int j : drives){
            if(i+j<=b)
                if(i+j>prices){
                    prices=i+j;
                }
        }
    }
    return (prices==0)?-1:prices;
}

int main(){
    int b,n,m;
    cin>>b>>n>>m;
    vector<int> keyboards,drives;
    
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        keyboards.push_back(ele);
    }
    for(int i=0;i<m;i++){
        int ele;
        cin>>ele;
        drives.push_back(ele);
    }
    int x;
    x=getmax(keyboards,drives,b);
    cout<<x;
    return 0;
}