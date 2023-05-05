#include <iostream>
#include <string>
using namespace std;
int N;
bool isbig(string a,string b);
int val(string a);
string word[50];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>word[i];
    }
    string temp;
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(!isbig(word[j],word[j+1])){
                temp=word[j];
                word[j]=word[j+1];
                word[j+1]=temp;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<word[i]<<'\n';
    }
}
bool isbig(string a,string b){
    int all_size=min(a.size(),b.size());
    int a_idx=0;
    int b_idx=0;
    while(a_idx<all_size&&b_idx<all_size){
        string a_;
        string b_;
        a_.push_back(a[a_idx++]);
        b_.push_back(b[b_idx++]);
        if(a_=="n"&&a_idx<a.size()){
            if(a[a_idx]=='g'){
                a_idx++;
                a_.push_back('g');
            }
        }
        if(b_=="n"&&b_idx<b.size()){
            if(b[b_idx]=='g'){
                b_idx++;
                b_.push_back('g');
            }
        }
        if(val(a_)>val(b_)){
            return 1;
        }
        else if(val(a_)<val(b_)){
            return 0;
        }
    }
    if(a.size()<b.size()){
        return 1;
    }
    else
        return 0;
}
int val(string a){
    if(a=="y"){
        return 0;
    }
    else if(a=="w"){
        return 1;
    }
    else if(a=="u"){
        return 2;
    }
    else if(a=="t"){
        return 3;
    }
    else if(a=="s"){
        return 4;
    }
    else if(a=="r"){
        return 5;
    }
    else if(a=="p"){
        return 6;
    }
    else if(a=="o"){
        return 7;
    }
    else if(a=="ng"){
        return 8;
    }
    else if(a=="n"){
        return 9;
    }
    else if(a=="m"){
        return 10;
    }
    else if(a=="l"){
        return 11;
    }
    else if(a=="i"){
        return 12;
    }
    else if(a=="h"){
        return 13;
    }
    else if(a=="g"){
        return 14;
    }
    else if(a=="e"){
        return 15;
    }
    else if(a=="d"){
        return 16;
    }
    else if(a=="k"){
        return 17;
    }
    else if(a=="b"){
        return 18;
    }
    else{
        return 19;
    }
}