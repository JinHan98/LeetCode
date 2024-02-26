#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
int N,T;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        priority_queue<int> k;
        for(int j=0;j<10;j++){
            cin>>N;
            k.push(N);
        }
        k.pop();
        k.pop();
        cout<<k.top()<<'\n';
    }
    
}