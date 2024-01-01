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
pair<int,int> setree(int start,int parent,int depth);
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
    setree(1,0,1);
    cout<<max(DP[1].first,DP[1].second);
}
pair<int,int> setree(int start,int parent, int depth){
    for(int i=0;i<tree[start].size();i++){
        if(parent!=tree[start][i]){
            pair<int,int> temp=setree(tree[start][i],start,depth+1);
            DP[start].first+=temp.second;
            if(temp.first>temp.second){
                DP[start].second+=temp.first;
            }
            else{
                DP[start].second+=temp.second;
            }
        }
    }
    DP[start].first+=val[start];
    return DP[start];
}