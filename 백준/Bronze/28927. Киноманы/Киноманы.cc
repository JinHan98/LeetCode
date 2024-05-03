#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int arr[2][3];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    int ans[2];
    for(int i=0;i<2;i++){
        ans[i]=0;
        ans[i]+=(arr[i][0]*3);
        ans[i]+=(arr[i][1]*20);
        ans[i]+=(arr[i][2]*120);
    }
    if(ans[0]>ans[1]){
        cout<<"Max";
    }
    else if(ans[0]==ans[1]){
        cout<<"Draw";
    }
    else{
        cout<<"Mel";
    }
}