#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
int N;
pair<int,int> num[500000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i].first;
        num[i].second=i;
    }
    sort(num,num+N);
    int ans=-10;
    for(int i=0;i<N;i++){
        if(num[i].second-i>ans)
            ans=num[i].second-i;
    }
    ans++;
    cout<<ans;

}