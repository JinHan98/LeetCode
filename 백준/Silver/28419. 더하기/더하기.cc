#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long num;
    long long odd=0;
    long long jjack=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        if(i%2==0){
            odd+=num;
        }
        else{
            jjack+=num;
        }
    }
    long long ans=0;
    if(odd!=jjack){
        if(N==3){
            if(odd>jjack){
                cout<<-1;
                return 0;
            }
        }
    }
    ans=odd-jjack;
    ans=abs(ans);
    cout<<ans;
}