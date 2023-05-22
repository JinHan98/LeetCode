#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;


int N;
int tree[200000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tree[i];
        if(tree[i]-N+i>ans)
            ans=tree[i]-N+i;
    }
    cout<<ans;
}