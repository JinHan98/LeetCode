#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long pow_1(int a, int b);
int main(){
    int len;
    string a;
    cin>>len;
    cin>>a;
    unsigned long long ans=0;
    for(int i=0;i<a.size();i++){
        ans+=((a[i]-'a'+1)*(pow_1(31,i)));
        ans%=1234567891;
    }
    cout<<ans;
}
long long pow_1(int a, int b){
    long long ans=1;
    if(b==0)
        return 1;
    for(int i=0;i<b;i++){
        ans*=a;
        a%=1234567891;
    }
    return ans;
}