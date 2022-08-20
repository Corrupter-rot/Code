#include<iostream>
#include<vector>

using namespace std;

void printmatrix(vector<vector<int>> matrix);

int rowdec(int r,int n){
    --r;
    if(r<0)
        return n-1;
    else
        return r;
}

int colinc(int c,int n){
    ++c;
    if(c>n-1)
        return 0;
    else 
        return c;
}

void sqmatrixprinter(int n){

}

void printmatrix(vector<vector<int>> matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the matrix no."<<endl;
    cin>>n;

    vector<vector<int>> matrix(n);
    for(int i=0;i<n;i++){
        matrix[i]=vector<int>(n,-1);
    }
    int number=1;
    int i=0,cr,cc,r,c;
    cr=0; cc=(n/2);
    int checker;
    while(i<(n*n)){
        checker=matrix[cr][cc];
        if(checker==-1){
            r=cr; c=cc;
            matrix[r][c]=number;
            ++number;
        }
        else{
            cr=r; cc=c;
            cr=colinc(cr,n);
            matrix[cr][cc]=number;
            ++number;
            
        }
        cr=rowdec(cr,n);
        cc=colinc(cc,n);
        i++;
    }
    //printmatrix(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;   
}