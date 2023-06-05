#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int num[9];
string k;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>k;
    int k_size=k.size();
    for(int i=0;i<k_size;i++){
        if(k[i]=='9'){
            num[6]++;
            continue;
        }
        num[k[i]-'0']++;
    }
    int ans=0;
    for(int i=0;i<9;i++){
        if(i==6){
            if(num[i]%2==1)
                num[i]++;
            if(num[i]/2>ans)
                ans=num[i]/2;
            continue;
        }
        if(num[i]>ans)
            ans=num[i];
    }
    cout<<ans;
}