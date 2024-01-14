#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int N;
int num[1000000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=1;
    int idx=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    int val=num[0];
    for(int i=1;i<N;i++){
        if(num[i]<val){
            if(ans<i-idx+1){
                ans=i-idx+1;
            }
        }
        else{
            idx=i;
            val=num[idx];
        }
    }
    cout<<ans;
}