#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
int T,N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    priority_queue<long long,vector<long long>,greater<long long> >k;
    for(int i=0;i<T;i++){
        cin>>N;
        long long temp;
        long long ans=1;
        for(int j=0;j<N;j++){
            cin>>temp;
            k.push(temp);
        }
        while(k.size()>1){
            long long mul=k.top();
            k.pop();
            mul*=(k.top());
            k.pop();
            ans*=(mul%1000000007);
            ans%=1000000007;
            k.push(mul);
        }
        while(!k.empty())
            k.pop();
        cout<<ans<<'\n';
    }
}