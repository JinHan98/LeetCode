#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T,S;
    cin>>T>>S;
    if(T>=12&&T<=16&&S==0){
        cout<<320;
    }
    else{
        cout<<280;
    }
}