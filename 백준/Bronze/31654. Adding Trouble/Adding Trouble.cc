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
    int A,B,C;
    cin>>A>>B>>C;
    if(A+B==C){
        cout<<"correct!";
    }
    else{
        cout<<"wrong!";
    }
}