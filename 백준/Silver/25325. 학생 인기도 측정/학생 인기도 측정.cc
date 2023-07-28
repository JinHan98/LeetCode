#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
struct cmp{
bool operator()(pair<int,string> &a, pair<int,string> &b) {
              if (a.first == b.first) {
                  return a.second > b.second;
              }
              else {
                  return a.first < b.first;
              }
          }
};

int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    map<string,int> k;
    priority_queue<pair<int,string>,vector<pair<int,string> >,cmp > q;
    cin>>N;
    string name;
    for(int i=0;i<N;i++){
        cin>>name;
        k[name]=0;
    }
    while(1){
        cin>>name;
        if(cin.eof())
            break;
        k[name]++;
    }
    for(auto iter=k.begin();iter!=k.end();iter++){
        q.push({iter->second,iter->first});
    }
    while(!q.empty()){
        cout<<q.top().second<<' '<<q.top().first<<'\n';
        q.pop();
    }
    return 0;
}