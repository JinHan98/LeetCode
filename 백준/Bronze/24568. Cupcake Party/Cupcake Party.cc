#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    int ans=a*8+b*3-28;
    if(ans<0){
        cout<<0;
    }
    else{
        cout<<ans;
    }

}
