#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,K;
bool issosu[1001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    int idx=0;
    int this_num=2;
    while(this_num<=N){
        for(int i=this_num;i<=N;i+=this_num){
            if(!issosu[i]){
                issosu[i]=true;
                idx++;
                if(idx==K){
                    cout<<i;
                    return 0;
                }
            }
        }
        for(int i=this_num+1;i<=N;i++){
            if(!issosu[i]){
                this_num=i;
                break;
            }
        }
    }
}