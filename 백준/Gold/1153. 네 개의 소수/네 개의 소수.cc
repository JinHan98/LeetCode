#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <unordered_map>
#include <cmath>
using namespace std;
int ans[4];
int N;
bool sosu[1000001];
vector<int> so;
void che();
int num[100];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    che();
    int idx=0;
    if(N%2==1){ //홀수일때
        if(N<8){
            cout<<-1;
            return 0;
        }
        ans[0]=2;
        N-=5;
        ans[1]=3;
        for(int i=0;i<so.size();i++){
            if(!sosu[N-so[i]]){
                cout<<2<<' '<<3<<' '<<so[i]<<' '<<N-so[i]<<'\n';
                return 0;
            }
        }
        
    }
    else{ // 짝수일때
        if(N<8){
            cout<<-1;
            return 0;
        }
        else if(N==8){
            cout<<2<<' '<<2<<' '<<2<<' '<<2<<'\n';
            return 0;
        }
        ans[0]=2;
        ans[1]=2;
        N-=4;
        for(int i=1;i<so.size();i++){
            if(!sosu[N-so[i]]){
                cout<<2<<' '<<2<<' '<<so[i]<<' '<<N-so[i]<<'\n';
                return 0;
            }
        }
    }
}
void che(){
    int i=2;
    while(i<=1000000){
        if(!sosu[i]){
            so.push_back(i);
            for(int j=i+i;j<=1000000;j+=i){
                sosu[j]=true;
            }
            i++;
        }
        else
            i++;
    }
}