#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N;
int arr[500000];
int sor[500000];
long long ans=0;
void divide(int start, int end);
void conquer(int start, int end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    divide(0,N-1);
    cout<<ans;
}
void divide(int start, int end){
    if(start<end){
        int mid=(start+end)/2;
        divide(start,mid);
        divide(mid+1,end);
        conquer(start,end);
    }
}
void conquer(int start, int end){
    int mid=(start+end)/2;
    int idx=start;
    int i=start;
    int j=mid+1;
    while(i<=mid&&j<=end){
        if(arr[i]<=arr[j]){
            sor[idx++]=arr[i++];
        }
        else{
            sor[idx++]=arr[j++];
            ans+=(mid-i+1);
        }
    }
    if(i>mid){
        while(j<=end){
            sor[idx++]=arr[j++];
        }
    }
    else{
        while(i<=mid){
            sor[idx++]=arr[i++];
        }
    }
    for(int k=start;k<=end;k++)
        arr[k]=sor[k];
}