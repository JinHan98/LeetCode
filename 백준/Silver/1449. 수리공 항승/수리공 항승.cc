#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,L;
int num[1000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>L;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    sort(num,num+N);
    int idx=1;
    int now=num[0];
    int ans=1;
    now+=L-1;
    while(idx<N){
        if(now>=num[idx]){
            idx++;
            continue;
        }
        else{
            ans++;
            now=num[idx++]+L-1;
        }
    }
    cout<<ans;
}