#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string s;
    int N;
    cin>>N;
    getline(cin,s);
    for(int i=1;i<=N;i++){
        getline(cin,s);
        cout<<i<<". ";
        cout<<s<<'\n';
    }
}
