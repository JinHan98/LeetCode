#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int ans=0;
    priority_queue<int,vector<int>,greater<int> > minus;
    priority_queue<int> plus;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        if(temp>0){
            plus.push(temp);
        }
        else
            minus.push(temp);
    }
    if(plus.empty()){
        ans+=minus.top();
    }
    else if(minus.empty()){
        ans-=plus.top();
    }
    else{
        int x=max(plus.top(),-minus.top());
        ans-=x;
    }

    while(!plus.empty()){
        int num=1;
        int mx=plus.top();
        ans+=mx;
        plus.pop();
        while(!plus.empty()){
            if(num<M){
                plus.pop();
            }
            else
                break;
            num++;
        }
        ans+=mx;
    }
    while(!minus.empty()){
        int num=1;
        int mx=minus.top();
        ans-=mx;
        minus.pop();
        while(!minus.empty()){
            if(num<M){
                minus.pop();
            }
            else
                break;
            num++;
        }
        ans-=mx;
    }
    cout<<ans;
}