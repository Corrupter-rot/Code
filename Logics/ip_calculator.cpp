#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

vector<int> dotsplit(string ip){
    int j=0;
    vector<int> arrip;
    string sub="";
    for(int i=0;i<ip.length();i++){
        if(ip[i]!='.'){
            if(ip[i]!='/')
                sub+=ip[i];
            else
                break;   
        }
        else{
            arrip.push_back(stoi(sub));
            sub="";
        }
    }
    arrip.push_back(stoi(sub));
    return arrip;
}

int slashsplit(string ip){
    string sub="";
    int i=ip.find("/")+1;
    for(i;i<ip.length();i++)
        sub+=ip[i];
    int ans=stoi(sub);
    return ans;
}

void Printarr(vector<int>arr){
    cout<<"Given IP: ";
    for( int i:arr)
        cout<<i<<" ";
    cout<<endl;
}

pair<int,int> tableip(int notation){
    pair<int,int> cidr;
    switch (notation){
        case 1 ... 8:
            cidr.first=1;
            break;
        case 9 ... 16:
            cidr.first=2;
            break;
        case 17 ... 24:
            cidr.first=3;
            break;
        case 25 ... 32:
            cidr.first=4;
            break;
        default:
            cidr.first=-1;
            break;
    }
    
    switch(notation%8){
        case 0:
            cidr.second=1;
            break;
        case 1:
            cidr.second=128;
            break;
        case 2:
            cidr.second=64;
            break;
        case 3:
            cidr.second=32;
            break;
        case 4: 
            cidr.second=16;
            break;
        case 5:
            cidr.second=8;
            break;
        case 6:
            cidr.second=4;
            break;
        case 7:
            cidr.second=2;
            break;
        default:
            cidr.second=-1;
            break;
    }
    if(cidr.first>0 && cidr.second>0)
        return cidr;
    else
        return cidr;
}

//notation to decimal
int ntd(int notation){
    switch(notation){
        case 1:
           return 255;
        case 128:
            return 128;
        case 64:
            return 192;
        case 32:
            return 224;
        case 16:
            return 240;
        case 8:
            return 248;
        case 4:
            return 252;
        case 2:
            return 254;
        default:
            return -1; 
    }

}
//Subnet mask:
void subnetcal(vector<int> ip,pair<int,int> cidr){
    for(int i=0;i<ip.size();i++){
        if(i<cidr.first-1)
            ip[i]=255;
        else if(i==cidr.first-1)
            ip[(cidr.first)-1]=ntd(cidr.second);
        else{
            ip[i]=0;
        }
    }
    cout<<"Subnet Mask: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<endl;    
}

//net_ip;
void netcal(vector<int> ip,pair<int,int> cidr){
    for(int i=0;i<ip.size();i++){
        if(i<cidr.first-1){
            continue;
        }
        else if(i==cidr.first-1)
            ip[i]=(ip[i]/cidr.second)*cidr.second;
        else
            ip[i]=0;
    }
    cout<<"Network IP: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<endl;    

    ip[ip.size()-1]+=1; 
    cout<<"First Host IP: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<endl;    

}

//broadcastip;
void broadcastip(vector<int> ip,pair<int,int> cidr){
    for(int i=0;i<ip.size();i++){
        if(i<cidr.first-1){
            continue;
        }
        else if(i==cidr.first-1){
            ip[i]=(((ip[i]/cidr.second)+1)*cidr.second)-1;
        }
        else
            ip[i]=255;
    }
    
    cout<<"Broadcast IP: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<endl;    
    ip[ip.size()-1]-=1;
    cout<<"Last Host IP: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<endl;    
    

}

int main(int len,char *arr[]){
    vector<int>arrip;
    int notation;
    pair<int,int>cidr=tableip(slashsplit(arr[1]));

    if(len==1){
        cout<<"This is an IP calculator. Give an IP address with CIDR."<<endl;
        cout<<"This will show you\n1.Network Address\n2.Broadcast IP\n3.First & Last Host IP"<<endl;
    }
    else if(len=2){
        arrip=dotsplit(arr[1]);
        Printarr(arrip);
        subnetcal(arrip,cidr);
        netcal(arrip,cidr);
        broadcastip(arrip,cidr);
    }
    else
        cout<<"Give an IP."<<endl;
    return 0;

}