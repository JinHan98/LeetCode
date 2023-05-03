#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct cmp{
bool operator()(pair<int, int>&a, pair<int, int>&b) {
            if(a.second==b.second){
                return a.first<b.first;
            }
            else
              return a.second<b.second;
          }
};
int N;
int main() {
    cin>>N;
    if(N==0){
        cout<<0;
        return 0;
    }
    priority_queue<pair<int,int> >out;
    priority_queue<pair<int,int>,vector<pair<int,int> >,cmp>in;
    int d,p;
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>d>>p;
        in.push({d,p});
    }
    int thisday=in.top().second;
    while(thisday>0){
        while(1){
            if(!in.empty()&&in.top().second==thisday){
                out.push(in.top());
                in.pop();
            }
            else
                break;
        }
        if(out.empty()){
            thisday--;
            continue;
        }
        ans+=out.top().first;
        out.pop();
        thisday--;
    }
    cout<<ans;
}
