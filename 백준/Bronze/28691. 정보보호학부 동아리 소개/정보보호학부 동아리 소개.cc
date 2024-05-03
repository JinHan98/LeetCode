#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string s;
    cin>>s;
    if(s=="M"){
        cout<<"MatKor";
    }
    else if(s=="W"){
        cout<<"WiCys";
    }
    else if(s=="C"){
        cout<<"CyKor";
    }
    else if(s=="A"){
        cout<<"AlKor";
    }
    else{
        cout<<"$clear";
    }
}