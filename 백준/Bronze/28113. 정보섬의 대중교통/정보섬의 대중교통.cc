#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,A,B;
    cin>>N>>A>>B;
    if(B<N){
        cout<<"Bus";
    }
    else{
        if(B==A){
            cout<<"Anything";
        }
        else if(B>A){
            cout<<"Bus";
        }
        else{
            cout<<"Subway";
        }
    }
}