#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

bool imyunsu(int N);
bool imhyunsu(int N);
int zarihap(int N);
bool issosu[2701];
bool issosu_and_notzegop(int N);
void che();
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    che();
    if(imyunsu(N)&&imhyunsu(N)){
        cout<<4;
    }
    else if(imyunsu(N)){
        cout<<1;
    }
    else if(imhyunsu(N)){
        cout<<2;
    }
    else{
        cout<<3;
    }

}
bool imyunsu(int N){
    if(N>=6&&zarihap(N)%2==1)
        return true;
    else
        return false;
}
int zarihap(int N){
    int ans=0;
    while(N>0){
        ans+=N%10;
        N/=10;
    }
    return ans;
}
bool imhyunsu(int N){
    if(N==2||N==4)
        return true;
    if(issosu_and_notzegop(N))
        return true;
    return false;
    
}
bool issosu_and_notzegop(int N){
    int count=0;
    if(issosu[N]){
        for(int i=2;i<N;i++){
            if(!issosu[i]){
                if(N%i==0){
                    count++;
                }
            }
        }
        if(count%2==0)
            return true;
        else
            return false;
    }
    return false;
}
void che(){
    for(int i=2;i<=2700;i++){
        if(issosu[i]==false){
            for(int j=i+i;j<=2700;j+=i){
                issosu[j]=true;
            }
        }
    }
}
/*
absolute 2 3 4 의  합으로 표현 자릿수 홀수
chiken number or starcraft number, and 합성수 , 소인수 짝수




*/