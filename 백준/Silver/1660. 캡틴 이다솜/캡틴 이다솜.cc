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
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    vector<int> tri(1);
    vector<int> DP(1);
    for(int i=1;i<=300000;i++){
        tri.push_back(tri[i-1]+i);
        if(tri[i]>300000)
            break;
    }
    for(int i=1;i<=300000;i++){
        DP.push_back(DP[i-1]+tri[i]);
        if(DP[i]>300000)
            break;
    }
    vector<int> ans(300001,1000000000);
    ans[0]=0;
    for(int i=0;i<DP.size();i++){
        for(int j=DP[i];j<=300000;j++){
            ans[j]=min(ans[j-DP[i]]+1,ans[j]);
        }
    }
    cin>>N;
    cout<<ans[N];
    return 0;
}