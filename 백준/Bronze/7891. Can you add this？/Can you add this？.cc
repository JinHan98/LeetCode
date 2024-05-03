#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int a,b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        cout<<a+b<<'\n';
    }
}
