#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<vector<int> >rk;
int N,K;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> temp(4);
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>temp[3]>>temp[0]>>temp[1]>>temp[2];
        rk.push(temp);
    }
    int ranking=1;
    int te=1;
    temp=rk.top();
    rk.pop();
    while(!rk.empty()){
        if(temp[0]==rk.top()[0]&&temp[1]==rk.top()[1]&&temp[2]==rk.top()[2]){
            if(rk.top()[3]==K){
                cout<<ranking;
                return 0;
            }
            te++;
        }
        else{
            if(rk.top()[3]==K){
                cout<<ranking+te;
                return 0;
            }
            ranking+=te;
            te=1;
        }
        temp=rk.top();
        rk.pop();
    }
    return 0;
    
}