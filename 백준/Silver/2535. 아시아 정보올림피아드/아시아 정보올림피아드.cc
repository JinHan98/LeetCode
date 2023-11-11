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
int people[1001];
int N;
priority_queue<pair<int,pair<int,int> > >k;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int c,n,s;
    for(int i=0;i<N;i++){
        cin>>c>>n>>s;
        k.push({s,{c,n}});
    }
    int ans=0;
    while(ans<3){
        if(people[k.top().second.first]<2){
            people[k.top().second.first]++;
            cout<<k.top().second.first<<' '<<k.top().second.second<<'\n';
            k.pop();
            ans++;
        }
        else{
            k.pop();
        }
    }
    
}