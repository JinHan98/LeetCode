#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct cmp{
bool operator()(pair<long long, long long>&a, pair<long long, long long>&b) {
              if (a.second == b.second) {
                  return a.first > b.first;
              }
              else {
                  return a.second < b.second;
              }
          }
};
long long N;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >, greater<pair<long long,long long> > > f;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,cmp > s;
    cin>>N;
    pair<long long,long long> temp;
    for(long long i=0;i<N;i++){
        cin>>temp.first>>temp.second;
        if(temp.first<=temp.second)
            f.push(temp);
        else
            s.push(temp);
    }
    long long current=0;
    while(!f.empty()){
        temp=f.top();
        if(current>=temp.first){
            current-=temp.first;
            current+=temp.second;
            f.pop();
        }
        else{
            cout<<0;
            return 0;
        }
    }
    while(!s.empty()){
        temp=s.top();
        if(current>=temp.first){
            current-=temp.first;
            if(current<0){
                cout<<0;
                return 0;
            }
            current+=temp.second;
            s.pop();
        }
        else{
            cout<<0;
            return 0;
        }
    }
    cout<<1;   
}
