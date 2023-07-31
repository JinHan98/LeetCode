#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int DP[100001];
int arr[100001];
int get_score(int a);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    if(N==1){
        cout<<0;
        return 0;
    }
    else if(N==2){
        cout<<get_score(arr[1]^arr[2]);
        return 0;
    }
    else if(N==3){
        cout<<get_score(arr[1]^arr[2]^arr[3]);
        return 0;
    }
    DP[2]=get_score(arr[1]^arr[2]);
    DP[3]=get_score(arr[1]^arr[2]^arr[3]);
    DP[4]=DP[2]+get_score(arr[3]^arr[4]);
    if(N==4){
        cout<<DP[4];
        return 0;
    }
    for(int i=5;i<=N-2;i++){
        DP[i]=max(DP[i-2]+get_score(arr[i-1]^arr[i]),DP[i-3]+get_score(arr[i-2]^arr[i-1]^arr[i]));
    }
    int ans=max(DP[N-3]+get_score(arr[N-2]^arr[N-1]^arr[N]),DP[N-2]+get_score(arr[N-1]^arr[N]));
    cout<<ans;
    return 0;
}
int get_score(int a){
    int score=0;
    while(a>0){
        if(a%2==1)
            score++;
        a/=2;
    }
    return score;
}