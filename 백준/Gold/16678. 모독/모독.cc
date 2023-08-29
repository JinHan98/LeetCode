#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int N;
map<int,int> honor;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        auto iter=honor.find(temp);
        if(iter!=honor.end()){
            honor[temp]++;
        }
        else{
            honor[temp]=1;
        }
    }
    int i=1;
    long long ans=0;
    for(auto iter=honor.begin();iter!=honor.end();){
        if(iter->second==1||iter->first==i){
            ans+=(iter->first-i);
            iter++;
        }
        else{
            ans+=(iter->first-i);
            iter->second--;
        }
        i++;
    }
    cout<<ans;
}