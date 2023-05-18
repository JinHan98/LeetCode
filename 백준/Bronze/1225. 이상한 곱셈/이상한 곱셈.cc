#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

string A,B;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long ans=0;
    cin>>A>>B;
    int A_size=A.size();
    int B_size=B.size();
    for(int i=0;i<A_size;i++){
        for(int j=0;j<B_size;j++){
            ans+=((A[i]-'0')*(B[j]-'0'));
        }
    }
    cout<<ans;
}