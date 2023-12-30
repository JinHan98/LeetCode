#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1){
        cin>>N>>M;
        if(N==0&&M==0)
            return 0;
        unordered_set<int> num;
        int temp;
        int ans=0;
        for(int i=0;i<N;i++){
            cin>>temp;
            num.insert(temp);
        }
        for(int i=0;i<M;i++){
            cin>>temp;
            auto iter=num.find(temp);
            if(iter!=num.end()){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
}