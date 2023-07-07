#include <iostream>
#include <algorithm>
using namespace std;

long long fact(int a);
string binary(long long a);
long long inverse(long long a);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    long long ans=fact(N);
    long long mod=fact(K)*fact(N-K);
    mod%=1000000007;
    mod=inverse(mod);
    ans*=mod;
    ans%=1000000007;
    cout<<ans;
}
long long fact(int a){
    long long ans=1;
    for(int i=2;i<=a;i++){
        ans*=i;
        ans%=1000000007;
    }
    return ans;
}
long long inverse(long long a){
    string k;
    k=binary(1000000005);
    long long ans=a;
    for(int i=1;i<k.size();i++){
        if(k[i]=='1'){
            ans*=ans;
            ans%=1000000007;
            ans*=a;
            ans%=1000000007;
        }
        else{
            ans*=ans;
            ans%=1000000007;
        }
    }
    return ans;
}

string binary(long long a){
    string ans;
    while(a>0){
        ans.push_back(a%2+'0');
        a/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}