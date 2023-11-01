#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int N;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int answer=1;
    int acc[13];
    for(int i=1;i<13;i++){
        acc[i]=acc[i-1]+month[i];
    }
    cin>>N;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >k;
    for(int i=0;i<N;i++){
        int s_m,s_d,e_m,e_d;
        cin>>s_m>>s_d>>e_m>>e_d;
        k.push({acc[s_m-1]+s_d,acc[e_m-1]+e_d});
    }
    if(k.top().first>acc[2]+1){
        cout<<0;
        return 0;
    }
    int val;
    priority_queue<int> ans;
    while(k.top().first<=acc[2]+1&&!k.empty()){
        ans.push(k.top().second);
        k.pop();
    }
    val=ans.top();
    ans.pop();
    while(val<acc[11]+1&&!k.empty()){
        if(k.top().first>val){
            cout<<0;
            return 0;
        }
        while(k.top().first<=val&&!k.empty()){
            ans.push(k.top().second);
            k.pop();
        }
        val=ans.top();
        answer++;
    }
    if(val>acc[11])
        cout<<answer;
    else
        cout<<0;
}