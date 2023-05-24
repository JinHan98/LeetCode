#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
pair<int,int> ans[10];
int isright(int a);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i=1;i<=9;i++){
        cin>>ans[i].first>>ans[i].second;
    }
    int ans=-1;
    for(int i=1;i<=9;i++){
        int temp=isright(i);
        if(temp==-2){
            cout<<-1;
            return 0;
        }
        if(temp!=-1){
            if(ans==-1){
                ans=temp;
            }
            else{
                cout<<-1;
                return 0;
            }
        }
    }
    if(ans!=-1){
        cout<<ans;
    }
    else
        cout<<-1;
}
int isright(int a){
    int first_p[10]={0,}; // 0 모름 1 아님 2 맞음
    int already=-1;
    if(ans[a].first==0){
        first_p[ans[a].second]=2;
        already=ans[a].second;
    }
    else{
        first_p[ans[a].second]=1;
    }
    for(int i=1;i<=9;i++){
        if(i==a)
            continue;
        if(ans[i].first==0){
            if(first_p[ans[i].second]==2){
                return -1;
            }
            else
                first_p[ans[i].second]=1;
            if(already==ans[i].second){
                return -1;
            }
        }
        else{
            if(first_p[ans[i].second]==1)
                return -1;
            else
                first_p[ans[i].second]=2;
            if(already==-1){
                already=ans[i].second;
            }
            else{
                if(already!=ans[i].second)
                    return -1;
            }
        }
    }
    if(already==-1){
        for(int i=1;i<=9;i++){
            if(first_p[i]==0){
                if(already==-1){
                    already=i;
                }
                else
                    return -2;
            }
        }
    }
    return already;
}