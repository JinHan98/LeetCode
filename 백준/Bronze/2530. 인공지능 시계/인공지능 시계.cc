#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

int A,B,C;
int sec;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>A>>B>>C;
    cin>>sec;
    int S=sec%60;
    sec-=S;
    int M=(sec/60)%60;
    sec-=(M*60);
    int H=sec/3600;
    H+=A;
    M+=B;
    S+=C;
    if(S>=60){
        M+=(S/60);
        S%=60;
    }
    if(M>=60){
        H+=(M/60);
        M%=60;
    }
    H%=24;
    cout<<H<<' '<<M<<' '<<S;
    
}