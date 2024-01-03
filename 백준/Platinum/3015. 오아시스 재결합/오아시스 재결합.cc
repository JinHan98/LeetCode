#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    stack<pair<int,int> >k;
    cin>>N;
    long long ans=0;
    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        int many=1;
        while(!k.empty()&&k.top().first<num){
            ans+=k.top().second;
            k.pop();
        }
        if(!k.empty()){
            if(k.top().first==num){
                ans+=k.top().second;
                many=k.top().second+1;
                if(k.size()>1)
                    ans++;
                k.pop();
            }
            else{
                ans++;
            }
        }
        k.push({num,many});
    }
    cout<<ans;
}

