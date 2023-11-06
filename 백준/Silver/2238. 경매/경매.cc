#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int U,N;
map<int,vector<string> > a;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>U>>N;
    for(int i=0;i<N;i++){
        int price;
        string name;
        cin>>name>>price;
        auto iter=a.find(price);
        if(iter!=a.end()){
            a[price].push_back(name);
        }
        else{
            a[price].push_back(name);
        }
    }
    for(auto iter=a.begin();iter!=a.end();iter++){
        q.push({iter->second.size(),iter->first});
    }
    cout<<a[q.top().second][0]<<' '<<q.top().second;
    return 0;
    
}
