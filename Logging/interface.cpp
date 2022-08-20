#include<bits/stdc++.h>

using namespace std;

void mainmenu();
void homescreen();

string encrypt(string name){
    string output="";
    for(int i=0;i<name.length();i++){
        output+=char(int(name[i])+i);
    }
    return output;
}

string decrypt(string name){
    string output="";
    for(int i=0;i<name.length();i++){
        output+=char(int(name[i])-i);
    }
    return output;
}


void userinfo(string username,string email,string age){
    fstream ufile;
    string file;
    file=encrypt(username)+".txt";
    ufile.open(file, ios::app);
    ufile<<encrypt(username)<<endl;
    ufile<<encrypt(email)<<endl;
    ufile<<encrypt(age)<<endl;
    ufile.close();
}

void userfile(string useranme, string password){
    fstream userfile;
    string file;
    file=encrypt(useranme)+".dat";
    userfile.open(file, ios::app);
    userfile<<encrypt(password);
    userfile.close();
}

int username_checker(string word){
    ifstream ufile;
    string file;
    file=encrypt(word)+".txt";
    ufile.open(file);
    if(ufile.is_open()){
        return 1;
    }
    ufile.close();
    return 0;
}

int verify(){
    string username,password;

    cout<<"-------------------------------------------------"<<endl;
    cout<<"Enter your Username: "; cin>>username;
    cout<<"Enter your Password: "; cin>>password;
    cout<<"-------------------------------------------------"<<endl;
    ifstream ufile;
    string file,word;
    file=encrypt(username)+".dat";
    ufile.open(file);
    if(ufile.is_open()){
        password=encrypt(password);
        while(getline(ufile,word)){
            if(password==word){
                return 1;
                break;
            }
            else{
                cout<<"Wrong password"<<endl;
                homescreen();
            }
        }
    }
    else{
        cout<<"Wrong Username"<<endl;
        homescreen();
    }
    ufile.close();
    return 0;
}

void displayinfo(){
    cout<<"Enter the username for which you want to info about"<<endl;
    string useranme;
    cin>>useranme;
    cout<<"-------------------------------------------------"<<endl;
    fstream ufile;
    string file,word;
    file=encrypt(useranme)+".txt";
    ufile.open(file);
    if(ufile.is_open()){
        while(getline(ufile,word)){
            cout<<decrypt(word)<<endl;
        }
    }
    else{
        cout<<"Username does not exists."<<endl;
    }
}

void logging(){
    string username,password;
    cout<<"----------------------------------"<<endl;
    cout<<"|         LOGGING SCREEN         |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Enter Username: "; cin>>username;
    cout<<"Enter Password: "; cin>>password;
    
    ifstream ufile;
    string file,word;
    file=encrypt(username)+".dat";
    ufile.open(file);
    if(ufile.is_open()){
        password=encrypt(password);
        while(getline(ufile,word)){
            if(word==password){
                cout<<"Login Successfull!!"<<endl<<endl;
                homescreen();
                break;
            }
            else{
                cout<<"Wrong password"<<endl<<endl;
                mainmenu();
            }
        }
    }
    else{
        cout<<"Enter a valid username please"<<endl<<endl;
        mainmenu();
    }
    ufile.close();
}

void registering(){
    string username,password,password1;
    cout<<"----------------------------------"<<endl;
    cout<<"|          REGISTERING           |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Choose a Username: "; cin>>username;
    int x=username_checker(username);
    if(x==1){
        cout<<"Username Taken!! Think about a new one"<<endl;
        cout<<"Try again [Y/N]"<<endl;
        char ans;
        cin>>ans;
        if(ans=='y'||ans=='Y'){
            registering();
        }
        else{
            mainmenu();
        }
    }
    
    string email,age;
    cout<<"Enter Email: "; cin>>email;
    cout<<"Enter Age: "; cin>>age;
    cout<<"Choose a Password: "; cin>>password;
    cout<<"Re-Enter the Password: "; cin>>password1;
    if(password==password1){
        cout<<"Registeration succesful"<<endl<<endl;
        userinfo(username,email,age);
        userfile(username,password);
        mainmenu();
    }
    else{
        cout<<"Password didn't not match"<<endl;
        mainmenu();
    }
}

void mainmenu(){
    int choice;
    cout<<"---------------"<<endl;
    cout<<"|  MAIN MENU  |"<<endl;
    cout<<"| 1. LOGIN IN |"<<endl;
    cout<<"| 2. REGISTER |"<<endl;
    cout<<"| 3. EXIT     |"<<endl;
    cout<<"---------------"<<endl;
    cout<<"Enter a choice ";
    cin>>choice;
    switch (choice)
    {
    case 1:{
        logging();
        break;
    }

    case 2:{
        registering();
        break;
    }
    
    case 3:{
        exit(0);
    }
    
    default:{
        cout<<"Enter a valid choice"<<endl;
        break;
    }    
    }
}

void homescreen(){
    cout<<"1. Display information about your account."<<endl;
    cout<<"Enter choice: ";
    int choice;
    cin>>choice;
    cout<<"-------------------------------------------------"<<endl;
    switch (choice)
    {
    case 1:{
        int x=verify();
        if(x==1){
        displayinfo();   
        break;}
    }
    default:
        break;
    }
}

int main(){
    mainmenu();
    return 0;
}
