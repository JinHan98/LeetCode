#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

long long N,M;
long long num[10001];
long long acc[10001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>num[i];
        acc[i]=acc[i-1]+num[i];
    }
    for(int i=0;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(acc[j]-acc[i]==M){
                ans++;
            }
            else if(acc[j]-acc[i]>M)
                break;
        }
    }
    cout<<ans;
}