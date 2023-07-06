#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <unordered_map>
#include <cmath>
using namespace std;
int N;
bool sosu[10000001];
void che();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    sosu[0]=true;
    sosu[1]=true;
    che();
    while(cin>>N){
        if(N%2==1){ //홀수일때
            if(N<8){
                cout<<"Impossible.\n";
                continue;
            }
            N-=5;
            for(int i=2;i+i<=N;i++){
                if(!sosu[N-i]&&!sosu[i]){
                    cout<<2<<' '<<3<<' '<<i<<' '<<N-i<<'\n';
                    break;
                }
            }
            
        }
        else{ // 짝수일때
            if(N<8){
                cout<<"Impossible.\n";
                continue;
            }
            else if(N==8){
                cout<<2<<' '<<2<<' '<<2<<' '<<2<<'\n';
                continue;
            }
            N-=4;
            for(int i=2;i+i<=N;i++){
                if(!sosu[N-i]&&!sosu[i]){
                    cout<<2<<' '<<2<<' '<<i<<' '<<N-i<<'\n';
                    break;
                }
            }
        }
    }
}
void che(){
    int i=2;
    while(i<=10000000){
        if(!sosu[i]){
            for(int j=i+i;j<=10000000;j+=i){
                sosu[j]=true;
            }
            i++;
        }
        else
            i++;
    }
}