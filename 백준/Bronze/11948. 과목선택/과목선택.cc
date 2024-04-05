#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    int ans=A+B+C+D+E+F;
    ans-=(min(A,min(B,min(C,D))));
    ans-=(min(E,F));
    cout<<ans;
}
