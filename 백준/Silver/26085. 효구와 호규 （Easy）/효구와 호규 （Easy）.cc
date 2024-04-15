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
int N,M,temp;
bool pane[1000][1000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    bool not_ans=false;
    int last=-1;
    int zero=0;
    int one=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        if(i>0){
            last=pane[i-1][0];
        }
        for(int j=0;j<M;j++){
            cin>>pane[i][j];
            if(!not_ans){
                if(last==-1){
                    last=pane[i][j];
                }
                else{
                    if(last==pane[i][j]){
                        not_ans=!not_ans;
                    }
                    last=pane[i][j];
                }
            }
            if(!pane[i][j]){
                zero++;
            }
            else
                one++;
        }
    }
    if(!not_ans){
        cout<<-1;
        return 0;
    }
    if(zero%2==0&&one%2==0){
        cout<<1;
    }
    else{
        cout<<-1;
    }
}