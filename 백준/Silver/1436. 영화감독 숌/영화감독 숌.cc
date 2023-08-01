#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string a(string b);

int main(){
    int N;
    int temp;
    int ans;
    cin>>N;
    unsigned long long k=665;
    while(N>0){
        k++;
        temp=k;
        ans=0;
        while(temp>0){
            if(temp%10==6)
                ans++;
            else
                ans=0;
            if(ans==3){
                N--;
                break;
            }
            temp/=10;
        }
    }
    cout<<k<<endl;
}
