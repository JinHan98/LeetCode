#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int N,M;
map<string,string> password;
set<int> val[101];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    string a,b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        password[a]=b;
    }
    for(int i=0;i<M;i++){
        cin>>a;
        cout<<password[a]<<'\n';
    }
    
}