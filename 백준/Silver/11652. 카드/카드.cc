#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;
int N;
map<long long,int> k;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    long long temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        auto iter=k.find(temp);
        if(iter==k.end()){
            k[temp]=1;
        }
        else{
            k[temp]++;
        }
    }
    long long ans=0;
    int mx=-1;
    for(auto iter=k.begin();iter!=k.end();iter++){
        if(iter->second>mx){
            mx=iter->second;
            ans=iter->first;
        }
    }
    cout<<ans;
}