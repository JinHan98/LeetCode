#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N;
map<string,int> k;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        auto iter=k.find(temp);
        if(iter==k.end()){
            k.insert({temp,1});
        }
        else
            k[temp]++;
    }
    int ans=0;
    string a;
    for(auto i:k){
        if(i.second>ans){
            a=i.first;
            ans=i.second;
        }
    }
    cout<<a;
}