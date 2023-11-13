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
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    set<int> A;
    set<int> B;
    cin>>N>>M;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        A.insert(temp);
    }
    for(int i=0;i<M;i++){
        cin>>temp;
        B.insert(temp);
    }
    vector<int> ans;
    for(auto iter=A.begin();iter!=A.end();iter++){
        auto iter2=B.find(*iter);
        if(iter2==B.end()){
            ans.push_back(*iter);
        }
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}