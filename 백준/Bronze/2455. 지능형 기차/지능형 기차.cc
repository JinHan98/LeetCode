#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

pair<int,int> people[4];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i=0;i<4;i++){
        cin>>people[i].first>>people[i].second;
    }
    int ans=0;
    int now=0;
    for(int i=0;i<4;i++){
        now-=people[i].first;
        now+=people[i].second;
        if(now>ans)
            ans=now;
    }
    cout<<ans;
}