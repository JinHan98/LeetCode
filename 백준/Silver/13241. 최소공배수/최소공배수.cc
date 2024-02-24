#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b);
long long A,B;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>A>>B;
    cout<<A*B/gcd(A,B);
    
}
long long gcd(long long a,long long b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
