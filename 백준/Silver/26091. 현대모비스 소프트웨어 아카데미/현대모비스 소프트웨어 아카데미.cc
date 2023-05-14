#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N,M;
int stat[100000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>stat[i];
    }
    sort(stat,stat+N);
    int start=0;
    int end=N-1;
    int ans=0;
    while(start<end){
        if(stat[start]+stat[end]>=M){
            ans++;
            start++;
            end--;
        }
        else {
            start++;
        }
    }
    cout<<ans;
}