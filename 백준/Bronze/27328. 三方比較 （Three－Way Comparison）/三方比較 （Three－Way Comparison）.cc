#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int A,B;
    cin>>A>>B;
    if(A<B){
        cout<<-1;
    }
    else if(A==B){
        cout<<0;
    }
    else{
        cout<<1;
    }
}