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
    int ans=0;
    int n,m,p,l;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int> >k;
    for(int i=0;i<n;i++){
        cin>>p>>l;
        vector<int> score(p);
        for(int j=0;j<p;j++){
            cin>>score[j];
        }
        if(p>=l){
            sort(score.begin(),score.end(),greater<int>());
            if(score[l-1]>0)
                k.push(score[l-1]);
            else
                k.push(1);
        }
        else
            k.push(1);
    }
    while(1){
        if(m-k.top()>=0&&!k.empty()){
            ans++;
            m-=k.top();
            k.pop();
        }
        else
            break;
    }
    cout<<ans;
}