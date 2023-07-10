#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N;
int num[50001];
int acc[50001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num[i];
        acc[i]=acc[i-1]+num[i];
    }
    int start_p=1;
    int end_p=2;
    int ans=0;
    while(start_p<=end_p){
        int left=acc[end_p-1]-acc[start_p-1];
        int right=acc[start_p-1]+acc[N]-acc[end_p-1];
        int m_val=min(left,right);
        if(m_val>ans)
            ans=m_val;
        if(left<right){
            end_p++;
            if(end_p>N)
                break;
        }
        else if(left>right){
            start_p++;
        }
        else{
            break;
        }
    }
    cout<<ans;
}