#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string N;
    int ans=0;
    stack<char> k;
    cin>>N;
    for(int i=0;i<N.size();i++){
        if(N[i]=='('){
            k.push(N[i]);
        }
        else{
            k.pop();
            if(N[i-1]=='(')
                ans+=k.size();
            else
                ans++;
        }
    }
    cout<<ans;
}