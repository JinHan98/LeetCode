#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;
int N,K;
string hambuger;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>N>>K;
    cin>>hambuger;
    vector<bool>isvisit(N);
    for(int i=0;i<N;i++){
        if(hambuger[i]=='P'){
            int j=i-K;
            if(j<0)
                j=0;
            for(;j<=i+K&&j<hambuger.size();j++){
                if(hambuger[j]=='H'&&!isvisit[j]){
                    ans++;
                    isvisit[j]=true;
                    break;
                }
            }
        }
    }
    cout<<ans;
    
}