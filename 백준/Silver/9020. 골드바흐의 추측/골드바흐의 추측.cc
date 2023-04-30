#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int N,T;
bool sosu[10001];
void BFS();
bool issosu(int a);
int re[4];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    sosu[2]=true;
    for(int i=3;i<=10000;i++){
        if(issosu(i)){
            sosu[i]=true;
        }
    }
    cin>>T;
    for(int k=0;k<T;k++){
        cin>>N;
        for(int i=N/2;i>=2;i--){
            if(sosu[i]){
                if(sosu[N-i]){
                    cout<<i<<' '<<N-i<<'\n';
                    break;
                }
            }
        }
    }
}
bool issosu(int a){
    if(a%2==0)
        return 0;
    for(int i=3;i*i<=a;i+=2){
        if(a%i==0)
            return 0;
    }
    return 1;
}