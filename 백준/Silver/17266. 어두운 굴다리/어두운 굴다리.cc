#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int ans=0;
    int temp=0;
    int position;
    cin>>position;
    ans=position;
    temp=position;
    for(int i=1;i<M;i++){
        cin>>position;
        int t=(position-temp)/2;
        if((position-temp)%2==1)
            t++;
        if(ans<t){
            ans=t;
        }
        temp=position;
    }
    if(ans<N-temp){
        ans=N-temp;
    }
    cout<<ans;
    
}