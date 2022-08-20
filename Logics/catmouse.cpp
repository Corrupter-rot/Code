#include<bits/stdc++.h>

using namespace std;

string catmouse(int cat1,int cat2, int mouse){
    string answer;
    if(int(abs(cat1-mouse))<int(abs(cat2-mouse))){
        answer="Cat A";
    }
    if(int(abs(cat1-mouse))>int(abs(cat2-mouse))){
        answer="Cat B";
    }
    else if(int(abs(cat1-mouse))==int(abs(cat2-mouse))){
        answer="Mouse C";
    }
    return answer;
    
}

int main(){
    int cat1,cat2,mouse;
    cin>>cat1>>cat2>>mouse;

    string answer= catmouse(cat1,cat2,mouse);
    cout<<answer;
}