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
vector<string> solution(vector<pair<string,int> > call,vector<int> point);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<pair<string,int> > call(N);
    vector<int> point(M);
    for(int i=0;i<N;i++){
        cin>>call[i].first>>call[i].second;
    }
    for(int j=0;j<M;j++){
        cin>>point[j];
    }
    vector<string> ans=solution(call,point);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
vector<string> solution(vector<pair<string,int> > call,vector<int> point){
    vector<string> ans(point.size());
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > k;
    for(int i=0;i<point.size();i++){
        k.push({point[i],i});
    }
    int call_idx=0;
    while(!k.empty()){
        pair<int,int> temp=k.top();
        if(temp.first<=call[call_idx].second){
            ans[temp.second]=call[call_idx].first;
            k.pop();
        }
        else{
            call_idx++;
        }
    }
    return ans;
}
