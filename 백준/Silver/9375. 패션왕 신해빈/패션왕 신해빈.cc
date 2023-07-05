#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
vector<int> combine[31];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    string a,b;
    combine[0].push_back(1);
    for(int i=1;i<=30;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i){
                combine[i].push_back(1);
            }
            else{
                combine[i].push_back(combine[i-1][j-1]+combine[i-1][j]);
            }
        }
    }
    for(int i=0;i<T;i++){
        long long ans=1;
        map<string,int> cloth;
        vector<string> kind;
        int N;
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>a>>b;
            auto iter=cloth.find(b);
            if(iter==cloth.end()){
                cloth[b]=1;
                kind.push_back(b);
            }
            else{
                cloth[b]++;
            }
        }
        if(kind.size()==1){
            cout<<combine[cloth[kind[0]]][1]<<'\n';
        }
        else{
            for(int i=0;i<kind.size();i++){
                ans*=combine[cloth[kind[i]]+1][1];
            }
            cout<<ans-1<<'\n';
        }
    }
}