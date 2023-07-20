#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
int ans[1000][2];
int N,M,T;
bool isvisit[1000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>T;
    bool op;
    queue<vector<int> > zero;
    queue<vector<int> > one;
    vector<int> temp(3);
    for(int i=0;i<N;i++){
        temp[0]=i;
        cin>>op>>temp[1]>>temp[2];
        if(op){
            one.push(temp);
        }
        else{
            zero.push(temp);
        }
    }
    int truck=0;
    int cur_weight=M;
    int time=0;
    while(1){
        if(zero.empty()&&one.empty())
            break;
        cur_weight=M;//내리기
        if(truck==0){
            if(zero.empty()){
                truck=1;
                time+=T;
                continue;
            }
            if(zero.front()[2]<=time){//싣기
                while(1){
                    if(cur_weight==0||zero.empty()||zero.front()[2]>time)
                        break;
                    if(cur_weight>=zero.front()[1]){
                        if(!isvisit[zero.front()[0]])
                            ans[zero.front()[0]][0]=time;
                        ans[zero.front()[0]][1]=time+T;
                        cur_weight-=zero.front()[1];
                        isvisit[zero.front()[0]]=true;
                        zero.pop();
                    }
                    else{
                        if(!isvisit[zero.front()[0]])
                            ans[zero.front()[0]][0]=time;
                        zero.front()[1]-=cur_weight;
                        cur_weight=0;
                        isvisit[zero.front()[0]]=true;
                    }
                }
            }
            else{

                if(one.empty()){
                    time=max(zero.front()[2],time);
                    continue;
                }
                if(zero.front()[2]>one.front()[2]){//반대편으로 가야함
                    time=max(one.front()[2],time);
                }
                else{
                    time=max(zero.front()[2],time);
                    continue;
                }
            }
            truck=1;
        }
        else{
            if(one.empty()){
                truck=0;
                time+=T;
                continue;
            }
            if(one.front()[2]<=time){//싣기
                while(1){
                    if(cur_weight==0||one.empty()||one.front()[2]>time)
                        break;
                    if(cur_weight>=one.front()[1]){
                        if(!isvisit[one.front()[0]])
                            ans[one.front()[0]][0]=time;
                        ans[one.front()[0]][1]=time+T;
                        cur_weight-=one.front()[1];
                        isvisit[one.front()[0]]=true;
                        one.pop();
                    }
                    else{
                        if(!isvisit[one.front()[0]])
                            ans[one.front()[0]][0]=time;
                        one.front()[1]-=cur_weight;
                        cur_weight=0;
                        isvisit[one.front()[0]]=true;
                    }
                }
            }
            else{
                if(zero.empty()){
                    time=max(one.front()[2],time);
                    continue;
                }
                if(one.front()[2]>zero.front()[2]){//반대편으로 가야함
                    time=max(zero.front()[2],time);
                }
                else{
                    time=max(one.front()[2],time);
                    continue;
                }
            }
            truck=0;

        }
        time+=T;
    }
    for(int i=0;i<N;i++){
        cout<<ans[i][0]<<' '<<ans[i][1]<<'\n';
    }
}