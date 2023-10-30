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
set<string> a;
vector<string> k;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        k.push_back(temp);
    }
    for(int i=k[0].size()-1;i>=0;i--){
        bool ans=true;
        for(int j=0;j<N;j++){
            auto iter=a.find(k[j].substr(i));
            if(iter!=a.end()){
                ans=false;
                break;
            }
            else{
                a.insert(k[j].substr(i));
            }
        }
        if(ans){
            cout<<k[0].size()-i;
            return 0;
        }
    }
}