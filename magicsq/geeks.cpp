#include<bits/stdc++.h>

using namespace std;

void generate(int n){
    vector<vector<int>> square(n);
    for(int i=0;i<n;i++){
        square[i]=vector<int>(n,0);
    }   
    int row,column;
    row=n/2; column=n-1;

    for(int num=1; num<=n*n;){
        if(row==-1 && column==n){
            column=n-2;
            row=0;   
        }
        else{
            if(column==n)
                column=0;
            if(row<0){
                row=n-1;
            }
        }
        if(square[row][column]){
            column-=2;
            row++;
            continue;
        }
        else
            square[row][column]=num++; //set number
        
        column++;
        row--;

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(4)<<square[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    generate(n);
    return 0;
}