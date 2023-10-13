#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
#include <map>
using namespace std;
int N,M,P;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>P;
    vector<int> rank(N);
    for(int i=0;i<N;i++){
        cin>>rank[i];
    }
    if(rank.empty()){
        cout<<1;
        return 0;
    }
    sort(rank.begin(),rank.end(),greater<int>());
    int ans=N+1;
    for(int i=0;i<N;i++){
        if(rank[i]<M){
            ans=i+1;
            break;
        }
        else if(rank[i]==M){
            ans=i+1;
            int temp;
            bool isstop=true;
            if(i!=N-1){
                for(int j=i+1;j<N;j++){
                    if(rank[j]!=rank[i]){
                        isstop=false;
                        temp=j;
                        break;
                    }
                }
            }
            else{
                temp=ans;
                isstop=false;
            }
            if(isstop){
                if(N+1>P){
                    ans=N+1;
                }
                break;
            }
            else{
                if(temp+1>P)
                    ans=temp+1;
                break;
            }
        }
    }
    if(ans>P)
        cout<<-1;
    else
        cout<<ans;
}