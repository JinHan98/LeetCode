#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=N-i;j>0;j--){
            cout<<' ';
        }
        for(int j=0;j<2*i-1;j++){
            cout<<'*';
        }
        cout<<'\n';
    }
}
