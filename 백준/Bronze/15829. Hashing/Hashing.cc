#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long pow_1(int a, int b);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int len;
    string a;
    cin>>len;
    cin>>a;
    long long num=1;
    unsigned long long ans=0;
    for(int i=0;i<a.size();i++){
        ans+=(a[i]-'a'+1)*num;
        num*=31;
        num%=1234567891;
        ans%=1234567891;
    }
    cout<<ans;
}