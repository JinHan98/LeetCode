#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

string binary(long long a);
int n;
long long po(int a);
long long m;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        if(m==1||m==2){
            cout<<0<<' '<<0<<'\n';
            continue;
        }
        string a=binary(m);
        int y=a.size()-1;
        int x=0;
        for(int i=1;i<y;i++){
            if(a[i]=='1'){
                x=y-i;
                break;
            }
        }
        if(x==0&&m%2==0){
            cout<<y-1<<' '<<y-1<<'\n';
            continue;
        }
        if(po(x+1)+po(y)-m<m-(po(x)+po(y)))
            cout<<x+1<<' '<<y<<'\n';
        else
            cout<<x<<' '<<y<<'\n';
    }
    
}
string binary(long long a){
    string ans;
    if(a==0)
        return "0";
    while(a>0){
        ans.push_back(a%2+'0');
        a/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
long long po(int a){
    long long k=1;
    if(a==0)
        return k;
    while(a>=1){
        k*=2;
        a--;
    }
    return k;
}