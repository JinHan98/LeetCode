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
    cin>>N>>K;
    int temp;
    cin>>temp;
    int ans=1;
    int l_num=temp+K;
    for(int i=1;i<N;i++){
        cin>>temp;
        if(temp+K>=l_num&&l_num>=temp){
            continue;
        }
        else{
            ans++;
            l_num=temp+K;
        }
    }
    cout<<ans;
    
}