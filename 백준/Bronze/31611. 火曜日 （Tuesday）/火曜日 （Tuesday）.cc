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
    int X;
    cin>>X;
    if(X%7==2){
        cout<<1;
    }
    else{
        cout<<0;
    }
}