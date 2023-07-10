#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N,K;
int arr[200000];
int many[100001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int ans=1;
    int s=0;
    int e=0;
    many[arr[s]]++;
    e++;
    while(e<N){
        if(many[arr[e]]<K){
            many[arr[e]]++;
            if(e+1-s>ans)
                ans=e+1-s;
        }
        else{
            while(1){
                if(arr[s]==arr[e]){
                    s++;
                    break;
                }
                many[arr[s]]--;
                s++;
            }
        }
        e++;
    }
    cout<<ans;
}