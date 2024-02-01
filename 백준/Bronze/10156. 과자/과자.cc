#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
using namespace std;
int K,N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>K>>N>>M;
    int ans=(K*N)-M;
    cout<<max(ans,0);

}