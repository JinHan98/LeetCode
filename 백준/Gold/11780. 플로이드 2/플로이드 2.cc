#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N,M;
vector<int> getmember(int start,int end,vector<int> ans,vector<vector<int> > route);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    vector<vector<int> > distance(N+1,vector<int>(N+1,1000000001));
    vector<vector<int> > route(N+1,vector<int>(N+1));
    int start,end,val;
    for(int i=0;i<M;i++){
        cin>>start>>end>>val;
        if(distance[start][end]>val)
            distance[start][end]=val;
    }
    for(int k=1;k<=N;k++){
        for(int j=1;j<=N;j++){
            for(int i=1;i<=N;i++){
                if(i==j)
                    continue;
                if(distance[i][j]>distance[i][k]+distance[k][j]){
                    route[i][j]=k;
                    distance[i][j]=distance[i][k]+distance[k][j];
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(distance[i][j]==1000000001)
                distance[i][j]=0;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)
                cout<<0<<' ';
            else
                cout<<distance[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            vector<int> ans;
            if(i==j||distance[i][j]==0){
                cout<<0<<'\n';
            }
            else{
                if(route[i][j]==0){
                    ans.push_back(i);
                    ans.push_back(j);
                }
                else{
                    ans=getmember(i,j,ans,route);
                }
                cout<<ans.size()<<' ';
                for(int k=0;k<ans.size();k++){
                    cout<<ans[k]<<' ';
                }
                cout<<'\n';
            }
        }
    }
}
vector<int> getmember(int start,int end,vector<int> ans,vector<vector<int> > route){
    if(route[start][end]!=0){
        vector<int> a=getmember(start,route[start][end],ans,route);
        vector<int> b=getmember(route[start][end],end,ans,route);
        a.pop_back();
        ans.insert(ans.begin(),a.begin(),a.end());
        ans.insert(ans.end(),b.begin(),b.end());
        return ans;

    }
    else{
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
}