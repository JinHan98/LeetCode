#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
long long N;
bool issosu(long long a);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        while(1){
            if(issosu(N)){
                cout<<N<<'\n';
                break;
            }
            N++;
        }
    }
    
}
bool issosu(long long a){
    if(a==1)
        return 0;
    else if(a==2)
        return 1;
    else if(a%2==0)
        return 0;
    else{
        for(long long i=3;i*i<=a;i++){
            if(a%i==0)
                return 0;
        }
        return 1;
    }
}
