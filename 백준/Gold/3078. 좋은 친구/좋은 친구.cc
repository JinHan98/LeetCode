#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N,K;
int many[21];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    queue<string> k;
    long long ans=0;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        if(k.size()<=K){
            k.push(temp);
            many[temp.size()]++;
        }
        else{
            many[k.front().size()]--;
            ans+=many[k.front().size()];
            k.pop();
            k.push(temp);
            many[temp.size()]++;
        }
    }
    while(!k.empty()){
        many[k.front().size()]--;
        ans+=many[k.front().size()];
        k.pop();
    }
    cout<<ans;
}