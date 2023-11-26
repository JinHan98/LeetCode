#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    vector<int> ball(N+1);
    int s,e,n;
    for(int i=0;i<M;i++){
        cin>>s>>e>>n;
        for(int j=s;j<=e;j++)
            ball[j]=n;
    }
    for(int i=1;i<=N;i++){
        cout<<ball[i]<<' ';
    }
}