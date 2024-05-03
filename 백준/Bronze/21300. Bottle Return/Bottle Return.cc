#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,t;
    a=0;
    for(int i=0;i<6;i++){
        cin>>t;
        a+=t;
    }
    cout<<a*5;

}
