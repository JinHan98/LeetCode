#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int N;
typedef struct
{
    int many;
    string name;
    int start;
    int end;
}submit;
struct cmp{
bool operator()(submit &a, submit &b) {
							//조건이 들어감 밑의 예시는 pair
              if (a.many == b.many) {
                  return a.name > b.name;
              }
              else {
                  return a.many < b.many;
              }
          }
};

set<string> name;
map<string,int> place;
map<int,string> rplace;
int all_time[10][50001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    string n,p;
    int s,e;
    int idx=0;
    for(int i=0;i<N;i++){
        cin>>n>>p>>s>>e;
        auto iter=name.find(n);
        if(iter==name.end()){
            name.insert(n);
            auto it=place.find(p);
            if(it==place.end()){ //없다면
                place[p]=idx++;
                rplace[idx-1]=p;
            }
            for(int i=s;i<e;i++)
                all_time[place[p]][i]++;
        }
        else{
            continue;
        }
    }
    priority_queue<submit,vector<submit>,cmp > k;
    int start=0,end=0;
    for(int i=0;i<place.size();i++){
        for(int j=1;j<=50000;j++){
            if(all_time[i][j]!=all_time[i][j-1]){
                if(start==end){
                    start=j;
                }
                else{
                    end=j-1;
                    k.push({all_time[i][end],rplace[i],start,end});
                    start=j;
                }
            }
        }
        if(all_time[i][start]!=0){
            end=50000;
            k.push({all_time[i][end],rplace[i],start,end});
        }
    }
    cout<<k.top().name<<' '<<k.top().start<<' '<<k.top().end+1;
    return 0;
}