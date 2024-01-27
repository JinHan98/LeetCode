#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

int N,U,L;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>U>>L;
    if(N>=1000){
        if((U>=8000||L>=260))
            cout<<"Very Good";
        else{
            cout<<"Good";
        }
    }
    else{
        cout<<"Bad";
    }
    
    
}