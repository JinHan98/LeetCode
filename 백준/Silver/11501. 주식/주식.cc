#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
#include <map>
using namespace std;
int T,N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        vector<long long> stock(N);
        for(int i=0;i<N;i++){
            cin>>stock[i];
        }
        long long ans=0;
        long long max_val=stock[N-1];
        for(int j=N-2;j>=0;j--){
            if(max_val>stock[j]){
                ans+=(max_val-stock[j]);
            }
            else{
                max_val=stock[j];
            }
        }
        cout<<ans<<'\n';
    }
    
}