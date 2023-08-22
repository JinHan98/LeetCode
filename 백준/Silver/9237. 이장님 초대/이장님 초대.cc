#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<int> k;
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        k.push(temp);
    }
    int ans=0;
    int idx=2;
    while (!k.empty())
    {
        if(ans<k.top()+idx){
            ans=k.top()+idx;
        }
        idx++;
        k.pop();
    }
    cout<<ans;
    
}
