#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
int N,M;
priority_queue<int> present;
int want[100000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num;
        present.push(num);
    }
    for(int i=0;i<M;i++){
        cin>>want[i];
    }
    for(int i=0;i<M;i++){
        if(present.empty()){
            cout<<0;
            return 0;
        }
        if(want[i]>present.top()){
            cout<<0;
            return 0;
        }
        else{
            if(present.top()-want[i]>0)
                present.push(present.top()-want[i]);
            present.pop();
        }
    }
    cout<<1;
}