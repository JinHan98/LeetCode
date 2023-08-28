#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
string L,R;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>L>>R;
    int L_point=0;
    int R_point=0;
    if(L.size()!=R.size()){
        cout<<0;
        return 0;
    }
    int ans=0;
    while(1){
        if(L[L_point]==R[R_point]){
            if(L[L_point]=='8')
                ans++;
            L_point++;
            R_point++;
            if(L_point==L.size())
                break;
        }
        else
            break;
    }
    cout<<ans;
}