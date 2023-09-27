#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
int N,X;
int people[250001];
int acc[250001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>X;
    for(int i=1;i<=N;i++){
        cin>>people[i];
        acc[i]=acc[i-1]+people[i];
    }
    int ans=0;
    int count=0;
    for(int i=X;i<=N;i++){
        if(acc[i]-acc[i-X]>ans){
            ans=acc[i]-acc[i-X];
            count=1;
        }
        else if(acc[i]-acc[i-X]==ans)
            count++;
    }
    if(ans==0){
        cout<<"SAD";
        return 0;
    }
    else{
        cout<<ans<<'\n'<<count;
    }
}
