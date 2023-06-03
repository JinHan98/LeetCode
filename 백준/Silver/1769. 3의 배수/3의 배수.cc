#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;


string k;
string Tostr();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>k;
    int ans=0;
    while(1){
        if(k.size()==1){
            cout<<ans<<'\n';
            if(k[0]=='3'||k[0]=='6'||k[0]=='9'){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
            break;
        }
        k=Tostr();
        ans++;
    }
    
}
string Tostr(){
    string re;
    int a=0;
    for(int i=0;i<k.size();i++){
        a+=(k[i]-'0');
    }
    while(a>0){
        re.push_back(a%10+'0');
        a/=10;
    }
    reverse(re.begin(),re.end());
    return re;
}