#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sockMerchant(int n,vector<int> ar){
    sort(ar.begin(),ar.end());
    int pair=0;
  
    for(int i=0;i<n;){
        if(ar[i]==ar[i+1]){
            pair++;
            i+=2;
        }
        else{
            i++;
        }
    }
    cout<<pair;
}


int main(){
    int n;
    vector<int> ar;
    cin>>n;
    for(int i=0;i<n;i++){
        int z;
        cin>>z;
        ar.push_back(z);
    }
    sockMerchant(n,ar);
    return 0;
}