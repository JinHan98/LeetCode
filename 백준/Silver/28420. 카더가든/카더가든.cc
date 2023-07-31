#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[300][300];
int get_cloud(int x, int y);
int N,M,a,b,c;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=1000000000;
    int temp=0;
    cin>>N>>M>>a>>b>>c;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp=get_cloud(i,j);
            if(temp>0&&ans>temp){
                ans=temp;
            }
        }
    }
    cout<<ans;
}
int get_cloud(int x, int y){
    int ans=1000000000;
    int temp=0;
    if(y+c<=M&&y-b>=0&&x+a<=N){
        for(int i=x;i<x+a;i++){
            for(int j=y;j<y+c;j++){
                temp+=map[i][j];
            }
        }
        for(int i=x;i<x+a;i++){
            for(int j=y-b;j<y;j++){
                temp+=map[i][j];
            }
        }
    }
    if(temp!=0)
        ans=min(ans,temp);
    temp=0;
    if(y+c<=M&&x+a<=N&&x+a+b<=N&&y+a+c<=M){
        for(int i=x;i<x+a;i++){
            for(int j=y;j<y+c;j++){
                temp+=map[i][j];
            }
        }
        for(int i=x+a;i<x+a+b;i++){
            for(int j=y+c;j<y+a+c;j++){
                temp+=map[i][j];
            }
        }
    }
    if(temp!=0)
        ans=min(ans,temp);
    temp=0;
    if(x+c<=N&&y+a<=M&&x-a>=0&&y-b>=0){
        for(int i=x;i<x+c;i++){
            for(int j=y;j<y+a;j++){
                temp+=map[i][j];
            }
        }
        for(int i=x-a;i<x;i++){
            for(int j=y-b;j<y;j++){
                temp+=map[i][j];
            }
        }
    }
    if(temp!=0)
        ans=min(ans,temp);
    return ans;
}