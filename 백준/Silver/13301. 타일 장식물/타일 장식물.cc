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
int N;
vector<long long> DP;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    DP=vector<long long>(N+2);
    DP[1]=1;
    DP[2]=1;
    for(int i=3;i<=N+1;i++){
        DP[i]=DP[i-1]+DP[i-2];
    }
    cout<<(DP[N]+DP[N+1])*2;
}