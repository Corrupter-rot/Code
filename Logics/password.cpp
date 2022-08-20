#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string password;
    cin>>password;
    
    if(int(password.length())<6){
        int length;
        length=6-int(password.length());
        cout<<length;
    }
    else if(int(password.length())>=6){
    int marks[5],upper=0,lower=0,special=0,number=0;
    for(int i=0;i<password.length();i++){
        if(isupper(password[i]))
            ++upper;
        if(islower(password[i]))
            ++lower;
        if(isdigit(password[i]))
            ++number;
        if(ispunct(password[i]))
            ++special;
    }
    for(int i=0;i<5;i++) marks[i]=0;
    marks[0]=1;
    if(upper>0)
        marks[1]++;
    if(lower>0)
        marks[2]++;
    if(number>0)
        marks[3]++;
    if(special>0)
        marks[4]++;
    int sum=0;
    for(int i=0;i<5;i++) sum+=marks[i];
    
    sum=5-sum;
    cout<<abs(sum);
    }
    return 0;
}