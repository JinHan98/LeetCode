#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    int ans=0;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        ans+=temp;
    }
    if(ans>0){
        cout<<"Right";
    }
    else if(ans==0){
        cout<<"Stay";
    }
    else{
        cout<<"Left";
    }
}