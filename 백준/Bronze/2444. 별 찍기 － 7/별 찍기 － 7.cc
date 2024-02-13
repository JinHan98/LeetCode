#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N-i;j++){
            cout<<' ';
        }
        for(int j=1;j<=i;j++){
            cout<<'*';
        }
        for(int j=i-1;j>=1;j--){
            cout<<'*';
        }
        cout<<'\n';
    }
    for(int i=N-1;i>=1;i--){
        for(int j=1;j<=N-i;j++){
            cout<<' ';
        }
        for(int j=1;j<=i;j++){
            cout<<'*';
        }
        for(int j=i-1;j>=1;j--){
            cout<<'*';
        }
        cout<<'\n';
    }
}