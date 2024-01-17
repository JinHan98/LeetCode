#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
map<int,int> x;
map<int,int> y;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    for(int i=0;i<3;i++){
        cin>>a>>b;
        auto iter=x.find(a);
        if(iter!=x.end())
            x[a]++;
        else
            x[a]=1;
        auto iter2=y.find(b);
        if(iter2!=y.end())
            y[b]++;
        else
            y[b]=1;
    }
    for(auto iter=x.begin();iter!=x.end();iter++){
        if(iter->second==1)
            cout<<iter->first<<' ';
    }
    for(auto iter=y.begin();iter!=y.end();iter++){
        if(iter->second==1)
            cout<<iter->first;
    }
    return 0;
}