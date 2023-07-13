#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <unordered_map>
#include <cmath>
using namespace std;
int N,K;
bool sosu[10001];
int ans[10000];
vector<int> so;
bool issosu(int a);
void che();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    sosu[0]=true;
    sosu[1]=true;
    che();
    cin>>N>>K;
    if(2*K>N){
        cout<<-1;
        return 0;
    }
    else if(2*K==N){
        for(int i=0;i<K;i++){
            cout<<2<<' ';
        }
        return 0;
    }
    else{
        if(N%2==0){//짝수
            if(K==1||N-(2*K)<0){
                cout<<-1;
                return 0;
            }
            if(K==2){
                for(int i=0;i<so.size();i++){
                    if(issosu(N-so[i])){
                        cout<<so[i]<<' '<<N-so[i];
                        return 0;
                    }
                }
            }
            else{
                N-=(2*(K-2));
                for(int i=0;i<K-2;i++){
                    cout<<2<<' ';
                }
                for(int i=0;i<so.size();i++){
                    if(issosu(N-so[i])){
                        cout<<so[i]<<' '<<N-so[i];
                        return 0;
                    }
                }
            }
        }
        else{
            if(K>3){
                for(int i=0;i<K-3;i++){
                    cout<<2<<' ';
                }
                cout<<3<<' ';
                N-=(2*(K-3));
                N-=3;
                for(int i=0;i<so.size();i++){
                    if(issosu(N-so[i])){
                        cout<<so[i]<<' '<<N-so[i];
                        return 0;
                    }
                }
            }
            else if(K==3){
                N-=3;
                cout<<3<<' ';
                for(int i=0;i<so.size();i++){
                    if(issosu(N-so[i])){
                        cout<<so[i]<<' '<<N-so[i];
                        return 0;
                    }
                }
            }
            else if(K==2){
                if(issosu(N-2)){
                    cout<<2<<' '<<N-2;
                }
                else
                    cout<<-1;
            }
            else{
                if(issosu(N)){
                    cout<<N;
                }
                else{
                    cout<<-1;
                }
            }
        }
    }
    
    
}
void che(){
    int i=2;
    while(i<=10000){
        if(!sosu[i]){
            so.push_back(i);
            for(int j=i+i;j<=10000;j+=i){
                sosu[j]=true;
            }
            i++;
        }
        else
            i++;
    }
}
bool issosu(int a){
    if(a==1)
        return 0;
    else if(a==2)
        return 1;
    if(a%2==0)
        return 0;
    else{
        for(int i=0;so[i]*so[i]<=a&&i<so.size();i++){
            if(a%so[i]==0)
                return 0;
        }
        return 1;
    }
}