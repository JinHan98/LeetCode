#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
int statue[100001];
int DP[100001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>statue[i];
    }
    int left_value=0;
    int right_value=0;
    for(int i=1;i<=N;i++){
        if(statue[i]==1){
            left_value++;
            right_value--;
        }
        else{
            right_value++;
            left_value--;
        }
        if(right_value<0)
            right_value=0;
        if(left_value<0)
            left_value=0;
        DP[i]=max(DP[i-1],left_value);
        DP[i]=max(DP[i],right_value);
    }
    cout<<DP[N];
}
