#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
int N,M;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>M;
        q.push(M);
    }
    while(!q.empty()){
        cout<<q.top()<<'\n';
        q.pop();
    }
    
}