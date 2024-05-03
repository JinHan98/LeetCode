#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    while(n>4){
        cout<<'V';
        n-=5;
    }
    for(int i=0;i<n;i++){
        cout<<'I';
    }
}