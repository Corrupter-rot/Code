// void migratoryBirds(vector<int>arr,int n){
//     for(int i=1;i<n;i++){
//         int current=arr[i];
//         int j=i-1;
//         while(arr[j]>current && j>=0){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=current;
//     } //or use the sort function
//     int max_count = 1, res = arr[0], curr_count = 1; 
//     for (int i = 1; i < n; i++) { 
//         if (arr[i] == arr[i - 1]) 
//             curr_count++; 
//         else { 
//             if (curr_count > max_count) { 
//                 max_count = curr_count; 
//                 res = arr[i - 1]; 
//             } 
//             curr_count = 1; 
//         } 
//     } 
//     if (curr_count > max_count) 
//     { 
//         max_count = curr_count; 
//         res = arr[n - 1]; 
//     } 
//     cout<<res;
// }

#include<bits/stdc++.h>

using namespace std;

void birds(vector<int> arr,int n){
    vector<int> record;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++) 
        record[i]=0;
    for(int i=0;i<arr.size();i++){
        ++record[arr[i]-1];   
    }
    for(int i=0;i<arr.size();i++) cout<<record[i];
    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++) 
        cin>>arr[i];
    birds(arr,n);
    return 0;
}
