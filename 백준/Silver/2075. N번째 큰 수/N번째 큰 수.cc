#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<int,vector<int>,greater<int> > k;
    cin>>N;
    int a;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a;  
            k.push(a);
            if(k.size()>N)
                k.pop();
        }
    }
    cout<<k.top();
}