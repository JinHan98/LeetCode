#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int ans[2];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int arr[2][5];
    for(int i=0;i<2;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<2;i++){
        ans[i]+=(6*arr[i][0]);
        ans[i]+=(3*arr[i][1]);
        ans[i]+=(2*arr[i][2]);
        ans[i]+=(1*arr[i][3]);
        ans[i]+=(2*arr[i][4]);
    }
    cout<<ans[0]<<' '<<ans[1];
}
