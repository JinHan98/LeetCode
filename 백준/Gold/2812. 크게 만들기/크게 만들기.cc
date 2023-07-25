#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,K;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string a;
    cin>>N>>K>>a;
    stack<char> k;
    k.push(a[0]);
    int mx=a.size();
    int idx=1;
    while(idx<mx){
        if(K==0)
            break;
        if(k.empty()||k.top()>=a[idx]){
            k.push(a[idx]);
            idx++;
        }
        else{
            k.pop();
            K--;
        }
    }
    string ans;
    if(!k.empty()){
        while(!k.empty()){
            if(K>0){
                K--;
                k.pop();
                continue;
            }
            ans.insert(ans.begin(),k.top());
            k.pop();
        }
    }
    ans+=a.substr(idx);
    cout<<ans;
}