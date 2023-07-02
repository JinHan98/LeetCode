#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<int,vector<int>,greater<int> > in;
    priority_queue<int,vector<int>,greater<int> > out;
    cin>>N;
    int TE,TX;
    for(int i=0;i<N;i++){
        cin>>TE>>TX;
        in.push(TE);
        out.push(TX);
    }
    pair<int,int> r_t;
    int current=0;
    int time=0;
    int ans=0;
    while(!in.empty()||!out.empty()){
        if(in.empty()||in.top()>out.top()){
            if(current>ans){
                ans=current;
                r_t.first=time;
                r_t.second=out.top();
            }
            time=out.top();
            out.pop();
            current--;
        }
        else if(out.empty()||in.top()<out.top()){
            current++;
            time=in.top();
            in.pop();
        }
        else{
            in.pop();
            out.pop();
        }
    }
    cout<<ans<<'\n';
    cout<<r_t.first<<' '<<r_t.second;
    return 0;
}