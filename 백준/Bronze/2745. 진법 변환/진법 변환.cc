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
string num;
int zinbub;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>num>>zinbub;
    int zinsu=1;
    for(int i=num.size()-1;i>=0;i--){
        int n=num[i];
        if(num[i]>='0'&&num[i]<='9'){
            n-='0';
        }
        else{
            n-='A';
            n+=10;
        }
        ans+=(n*zinsu);
        zinsu*=zinbub;
    }
    cout<<ans;
}