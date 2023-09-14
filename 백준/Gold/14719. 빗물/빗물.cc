#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int H,W;
int height[500];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>H>>W;
    for(int i=0;i<W;i++){
        cin>>height[i];
    }
    int max_int=height[0];
    int max_int_index=0;
    int temp=0;
    int ans=0;
    int mul=1;
    for(int i=1;i<W;i++){
        if(max_int<=height[i]){
            for(int j=max_int_index;j<=i;j++){
                if(height[j]<max_int){
                    ans+=(max_int-height[j]);
                    height[j]=max_int;
                }
            }
            max_int=height[i];
            max_int_index=i;
        }
        else{
            if(height[i]>height[i-1]){
                for(int j=max_int_index+1;j<=i;j++){
                    if(height[j]<height[i]){
                        ans+=(height[i]-height[j]);
                        height[j]=height[i];
                    }
                }
            }
        }
    }
    cout<<ans;
}