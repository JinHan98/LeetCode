#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

int T,N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        vector<int> rank(N);
        vector<pair<int,int> > score(N);
        vector<int> people(N);
        vector<int> many(N);
        unordered_set<int> cant;
        for(int j=0;j<N;j++){
            cin>>rank[j];
            people[rank[j]]++;
        }
        for(int j=1;j<N;j++){
            if(people[j]==0)
                break;
            if(people[j]!=6){
                cant.insert(j);
            }
        }
        int ra=1;
        for(int j=0;j<N;j++){
            auto iter=cant.find(rank[j]);
            if(iter!=cant.end()){
                continue;
            }
            else{
                if(many[rank[j]]<4){
                    many[rank[j]]++;
                    score[rank[j]].first+=ra;
                    ra++;
                }
                else if(many[rank[j]]==4){
                    many[rank[j]]++;
                    score[rank[j]].second=ra;
                    ra++;
                }
                else{
                    ra++;
                }
            }
        }
        int ans=-1;
        pair<int,int> ans_val;
        for(int j=1;j<N;j++){
            if(score[j].first!=0&&score[j].second!=0){
                if(ans==-1){
                    ans=j;
                    ans_val=score[j];
                }
                else{
                    if(ans_val>score[j]){
                        ans=j;
                        ans_val=score[j];
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }

}