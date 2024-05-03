#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    bool ans=true;
    int temp;
    for(int i=0;i<8;i++){
        cin>>temp;
        if(temp==9){
            ans=false;
        }
    }
    if(ans){
        cout<<'S';
    }
    else{
        cout<<'F';
    }
}