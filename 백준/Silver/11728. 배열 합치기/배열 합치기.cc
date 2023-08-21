#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
using namespace std;
int a_num[1000000];
int b_num[1000000];
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>a_num[i];
    }
    for(int j=0;j<M;j++){
        cin>>b_num[j];
    }
    int a_idx=0;
    int b_idx=0;
    while(a_idx<N||b_idx<M){
        if(a_idx>N-1){
            cout<<b_num[b_idx++]<<' ';
        }
        else if(b_idx>M-1)
            cout<<a_num[a_idx++]<<' ';
        else{
            if(a_num[a_idx]>b_num[b_idx])
                cout<<b_num[b_idx++]<<' ';
            else
                cout<<a_num[a_idx++]<<' ';
        }
    }
    
}
