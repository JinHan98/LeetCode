#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string a="WelcomeToSMUPC";
    int N;
    cin>>N;
    N%=a.size();
    if(N!=0)
        cout<<a[N-1];
    else
        cout<<a.back();
}