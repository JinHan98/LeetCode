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
long long s,e;
long long num[1000001];
bool ans[1000001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>s>>e;
    for(long long i=1;i<=1000000;i++){
        num[i]=i*i;
    }
    for(long long i=2;i<=1000000;i++){
        if(num[i]>e)
            break;
        long long temp=(s/num[i])*num[i];
        if(temp<s)
            temp+=num[i];
        while(temp-s<=e-s){
            ans[temp-s]=true;
            temp+=num[i];
        }
    }
    int answer=0;
    for(int i=0;i<e-s+1;i++){
        if(ans[i]==false)
            answer++;
    }
    cout<<answer;
}