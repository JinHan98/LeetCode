#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int ans=0;
    int temp;
    stack<int> q;
    for(int i=0;i<N;i++){
        cin>>temp;
        q.push(temp);
    }
    temp=q.top();
    q.pop();
    while(!q.empty()){
        if(temp>q.top()){
            temp=q.top();
            q.pop();
        }
        else{
            ans+=(q.top()+1-temp);
            temp--;
            q.pop();
        }
    }
    cout<<ans;
}