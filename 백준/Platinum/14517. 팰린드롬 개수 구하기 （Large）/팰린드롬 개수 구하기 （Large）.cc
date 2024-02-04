#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

string S;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>S;
    vector<int>DP(S.size());
    for(int i=0;i<S.size();i++){
        for(int j=i;j<S.size();j++){
            if(S[i]==S[j]){
                DP[j]++;
                for(int k=j+1;k<S.size();k++){
                    DP[j]+=DP[k];
                    DP[j]%=10007;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<S.size();i++){
        ans+=DP[i];
        ans%=10007;
    }
    cout<<ans;
}