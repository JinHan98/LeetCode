#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,num;
    int ans=0;
    int temp=0;
    cin>>N;
    cin>>num;
    int mx=num;
    for(int i=1;i<N;i++){
        cin>>num;
        if(mx>num){
            temp++;
            if(temp>ans)
                ans=temp;
        }
        else{
            mx=num;
            temp=0;
        }
    }
    cout<<ans;
}