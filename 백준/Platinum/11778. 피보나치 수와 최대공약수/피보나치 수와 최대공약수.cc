#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

long long N,M;
long long gcd(long long a, long long b);
void multiply(long long F[2][2], long long M[2][2]);
void power(long long F[2][2], long long n);
long long fib(long long n);

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    if(M>N){
        long long temp=M;
        M=N;
        N=temp;
    }
    long long ans=gcd(N,M);
    cout<<fib(ans)%1000000007;
}
long long gcd(long long a, long long b){
    if(b==0)
        return a;
    else{
        return gcd(b,a%b);
    }
}
long long fib(long long n)
{
    long long F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}
void power(long long F[2][2], long long n)
{
    if( n == 0 || n == 1)
        return;
    long long M[2][2] = {{1,1},{1,0}};

    power(F, n/2);

    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);
}
void multiply(long long F[2][2], long long M[2][2])
{
    long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];

    long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x%1000000007;
    F[0][1] = y%1000000007;
    F[1][0] = z%1000000007;
    F[1][1] = w%1000000007;

}