#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
char word[100000];
bool isspend[100000];
struct cmp{
bool operator()(pair<char, int>&a, pair<char, int>&b) {
              if (a.first == b.first) {
                  return a.second < b.second;
              }
              else {
                  return a.first > b.first;
              }
          }
};
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string ans;
    string sang;
    string a,b;
    cin>>N;
    int idx=N-1;
    priority_queue<pair<char,int>,vector<pair<char,int> >,cmp >k;
    for(int i=0;i<N;i++){
        cin>>word[i];
        k.push({word[i],i});
    }
    while(!k.empty()&&idx>0){
        isspend[idx]=true;
        sang.push_back(word[idx--]);
        while(!k.empty()){
            if(isspend[k.top().second])
                k.pop();
            else{
                ans.push_back(k.top().first);
                isspend[k.top().second]=true;
                k.pop();
                break;
            }
        }
        if(k.empty())
            break;
        while(isspend[idx]){
            idx--;
        }
        if(idx<0)
            break;
    }
    if(ans<sang){
        cout<<"DA"<<'\n';
    }
    else
        cout<<"NE"<<'\n';
    cout<<ans;
}
