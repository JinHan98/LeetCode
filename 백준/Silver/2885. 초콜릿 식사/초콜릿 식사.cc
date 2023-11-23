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
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int choco=1;
    while(choco<N)
        choco*=2;
    int piece=choco;
    int br=1;
    if(choco==N){
        cout<<choco<<' '<<0;
        return 0;
    }
    while(1){
        choco/=2;
        if(N>=choco){
            N-=choco;
        }
        if(N==0){
            cout<<piece<<' '<<br;
            return 0;
        }
        br++;
    }
}