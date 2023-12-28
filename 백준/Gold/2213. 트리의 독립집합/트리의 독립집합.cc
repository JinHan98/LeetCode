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
vector<int> tree[10001];
pair<int,int> DP[10001];
int val[10001];
pair<vector<int>,vector<int> > recursive[10001];
pair<int,int> setree(int start,int parent);
void DFS(int a);
vector<int> ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>val[i];
    }
    int start,end;
    for(int i=0;i<N-1;i++){
        cin>>start>>end;
        tree[start].push_back(end);
        tree[end].push_back(start);
    }
    setree(1,0);
    cout<<max(DP[1].first,DP[1].second)<<'\n';
    if(DP[1].first>DP[1].second){
        ans.push_back(1);
        for(int i=0;i<recursive[1].first.size();i++){
            DFS(recursive[1].first[i]);
        }
    }
    else{
        for(int i=0;i<recursive[1].second.size();i++){
            DFS(recursive[1].second[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    return 0;
}
pair<int,int> setree(int start,int parent){
    bool leaf=true;
    for(int i=0;i<tree[start].size();i++){
        if(tree[start][i]!=parent){
            pair<int,int> temp=setree(tree[start][i],start);
            DP[start].first+=temp.second;
            recursive[start].first.insert(recursive[start].first.end(),recursive[tree[start][i]].second.begin(),recursive[tree[start][i]].second.end());
            DP[start].second+=max(temp.first,temp.second);
            if(temp.first>temp.second){
                recursive[start].second.push_back(tree[start][i]);
            }
            else{
                recursive[start].second.insert(recursive[start].second.end(),recursive[tree[start][i]].second.begin(),recursive[tree[start][i]].second.end());
            }
            leaf=false;
        }
    }
    if(leaf){
        return DP[start]={val[start],0};
    }
    else{
        DP[start].first+=val[start];
        return DP[start];
    }
}
void DFS(int a){
    ans.push_back(a);
    for(int i=0;i<recursive[a].first.size();i++)
        DFS(recursive[a].first[i]);
}