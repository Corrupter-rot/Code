#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,p;
    cin>>n>>p;
    int pages;
    pages=min(p/2,(n-p)/2);
    cout<<(pages==0)?1:pages;
    return 0;
}
    