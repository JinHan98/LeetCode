#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int fib[100];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    fib[1]=1;
    for(int i=2;i<100;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    int N;
    cin>>N;
    cout<<fib[N];
    
}