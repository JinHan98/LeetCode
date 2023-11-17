#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int N,K;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<int> k;
    cin>>N>>K;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        k.push(temp);
        if(k.size()>K)
            k.pop();
    }
    cout<<k.top();
}