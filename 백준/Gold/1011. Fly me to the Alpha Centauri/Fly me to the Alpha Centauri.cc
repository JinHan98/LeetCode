#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;
vector<int> k;
int T;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    k.push_back(0);
    cin>>T;
    int temp=1;
    int idx=1;
    bool up=false;
    while(temp>0){
        k.push_back(temp);
        temp+=idx;
        if(!up){
            idx++;
            up=true;
        }
        else{
            up=false;
        }
    }
    for(int i=0;i<T;i++){
        cin>>a>>b;
        int ans=b-a;
        cout<<lower_bound(k.begin(),k.end(),ans)-k.begin()<<'\n';
    }
}