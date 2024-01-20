#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
int N,M;
int num[101];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int s,e;
    for(int i=1;i<=N;i++){
        num[i]=i;
    }
    for(int i=0;i<M;i++){
        cin>>s>>e;
        reverse(num+s,num+e+1);
    }
    for(int i=1;i<=N;i++)
        cout<<num[i]<<' ';

    
}