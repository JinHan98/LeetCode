#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int M,t,N;
int arr_time[10000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>M>>t>>N;
    queue<pair<int,int> > left;
    queue<pair<int,int> > right;
    for(int i=0;i<N;i++){
        int arr;
        string which;
        cin>>arr>>which;
        if(which[0]=='l'){
            left.push({arr,i});
        }
        else{
            right.push({arr,i});
        }
    }
    bool position=false; //false이면 left
    int current_time=0;
    while(!left.empty()||!right.empty()){
        int current_people=0; //현재 타고있는 사람
        if(!position){
            if(left.empty()){
                if(current_time>=right.front().first){
                    current_time+=t;
                }
                else{
                    current_time=t+right.front().first;
                }
                position=!position;
                continue;
            }
            if(left.front().first<=current_time){
                while(current_people<M&&!left.empty()){
                    if(left.front().first<=current_time){
                        arr_time[left.front().second]=current_time+t;
                        left.pop();
                        current_people++;
                    }
                    else
                        break;
                }
                current_time+=t;
                position=!position;
            }
            else{
                if(right.empty()||left.front().first<=right.front().first){//그대로
                    current_time=left.front().first;
                    continue;
                }
                else{//right로 가야함
                    current_time=max(current_time,right.front().first);
                    current_time+=t;
                    position=!position;
                }
            }
            
        }
        else{
            if(right.empty()){
                if(current_time>=left.front().first){
                    current_time+=t;
                }
                else{
                    current_time=t+left.front().first;
                }
                position=!position;
                continue;
            }
            if(right.front().first<=current_time){
                while(current_people<M&&!right.empty()){
                    if(right.front().first<=current_time){
                        arr_time[right.front().second]=current_time+t;
                        right.pop();
                        current_people++;
                    }
                    else
                        break;
                }
                current_time+=t;
                position=!position;
            }
            else{
                if(left.empty()||right.front().first<=left.front().first){//그대로
                    current_time=right.front().first;
                    continue;
                }
                else{//left로 가야함
                    current_time=max(current_time,left.front().first);
                    current_time+=t;
                    position=!position;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<arr_time[i]<<'\n';
    }
}