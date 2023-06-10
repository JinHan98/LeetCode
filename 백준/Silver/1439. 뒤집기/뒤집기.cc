#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;


string k;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>k;
    int k_size=k.size();
    char t;
    if(k[0]=='1')
        t='0';
    else
        t='1';
    for(int i=1;i<k_size;i++){
        if(k[i]==t&&k[i-1]!=t)
            ans++;
    }
    cout<<ans;
    
}