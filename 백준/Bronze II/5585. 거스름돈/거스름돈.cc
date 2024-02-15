#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    N=1000-N;
    int ans=0;
    for(int i=100;i>=1;i/=10){
        if(N>=5*i){
            ans++;
            N-=(5*i);
        }
        ans+=(N/i);
        N%=i;
    }
    cout<<ans;
}