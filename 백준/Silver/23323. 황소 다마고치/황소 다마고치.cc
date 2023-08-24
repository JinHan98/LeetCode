#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        long long a,b;
        cin>>a>>b;
        int k=0;
        while(a>0){
            a/=2;
            k++;
        }
        cout<<k+b<<'\n';
    }
}