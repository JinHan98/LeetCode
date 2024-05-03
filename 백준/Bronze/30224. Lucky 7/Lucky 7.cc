#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    if(N%7==0){
        bool div=false;
        while(N>0){
            int temp=N%10;
            if(temp==7){
                div=true;
                break;
            }
            N/=10;
        }
        if(div){
            cout<<3;
        }
        else{
            cout<<1;
        }
    }
    else{
        bool div=false;
        while(N>0){
            int temp=N%10;
            if(temp==7){
                div=true;
                break;
            }
            N/=10;
        }
        if(div){
            cout<<2;
        }
        else
            cout<<0;
    }

}