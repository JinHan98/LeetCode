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
vector<int> tree[100001];
int DP[100001][18];
int depth[100001];
int N,M;
void setree(int start,int level,int parent);
int find_parent(int a, int b);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int a,b;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    setree(1,1,0);
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        cout<<find_parent(a,b)<<'\n';
    }
}
void setree(int start,int level,int parent){
    depth[start]=level;
    DP[start][0]=parent;
    int i=1;
    while(DP[DP[start][i-1]][i-1]!=0){
        DP[start][i]=DP[DP[start][i-1]][i-1];
        i++;
    }
    for(int i=0;i<tree[start].size();i++){
        if(tree[start][i]!=parent){
            setree(tree[start][i],level+1,start);
        }
    }
}
int find_parent(int a, int b){
    if(a==1||b==1)
        return 1;
    if(depth[a]!=depth[b]){
        if(depth[a]<depth[b]){
            int temp=a;
            a=b;
            b=temp;
        }
        for(int i=17;i>=0;i--){
            if(depth[DP[a][i]]>=depth[b]){
                a=DP[a][i];
            }
        }
        int ans=a;
        if(a!=b){
            for(int i=17;i>=0;i--){
                if(DP[a][i]!=DP[b][i]){
                    a=DP[a][i];
                    b=DP[b][i];
                }
                ans=DP[a][i];
            }
        }
        return ans;
    }
    else{
        int ans=a;
        if(a!=b){
            for(int i=17;i>=0;i--){
                if(DP[a][i]!=DP[b][i]){
                    a=DP[a][i];
                    b=DP[b][i];
                }
                ans=DP[a][i];
            }
        }
        return ans;
    }
}