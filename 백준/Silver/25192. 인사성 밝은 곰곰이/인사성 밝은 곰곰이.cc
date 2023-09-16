#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int ans=0;
    string temp;
    set<string> k;
    for(int i=0;i<N;i++){
        cin>>temp;
        if(temp=="ENTER"){
            k.clear();
        }
        else{
            auto iter=k.find(temp);
            if(iter==k.end()){
                ans++;
                k.insert(temp);
            }
        }
    }
    cout<<ans;
    
}