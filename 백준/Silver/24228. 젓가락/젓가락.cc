#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
long long N,R;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>R;
    if(N==1){
        cout<<R*2;
    }
    else{
        long long ans=0;
        ans=N+1+(2*(R-1));
        cout<<ans;
    }
    
}