#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <unordered_map>
#include <cmath>
#include <map>
using namespace std;
int n;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        int many;
        unordered_map<long long,int> count;
        cin>>many;
        for(int j=0;j<many;j++){
            long long temp;
            cin>>temp;
            auto iter=count.find(temp);
            if(iter==count.end()){
                count[temp]=1;
            }
            else{
                count[temp]++;
            }
        }
        bool SYJKGW=true;
        for(auto iter=count.begin();iter!=count.end();iter++){
            if(iter->second>many/2){
                cout<<iter->first<<'\n';
                SYJKGW=false;
                break;
            }
        }
        if(SYJKGW){
            cout<<"SYJKGW"<<'\n';
        }
    }
}