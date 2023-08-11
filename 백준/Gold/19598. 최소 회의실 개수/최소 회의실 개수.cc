#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <limits>

using namespace std;
int N;
priority_queue<int,vector<int>,greater<int> > s;
priority_queue<int,vector<int>,greater<int> > e;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        int t_s,t_e;
        cin>>t_s>>t_e;
        s.push(t_s);
        e.push(t_e);
    }
    int now=0;
    int ans=0;
    while(!e.empty()||!s.empty()){
        if(!s.empty()&&e.top()>s.top()){
            now++;
            if(now>ans)
                ans=now;
            s.pop();
        }
        else if(!s.empty()&&e.top()==s.top()){
            e.pop();
            s.pop();
        }
        else{
            now--;
            e.pop();
        }
    }
    cout<<ans;
}
