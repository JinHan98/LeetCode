#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int L,R;
bool isvisit[100001];
int possible[100001];
int get_func(int a);
int mix_num(int a,int b);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i=1;i<=100000;i++){
        if(!isvisit[i]){
            possible[i]=get_func(i);
        }
    }
    cin>>L>>R;
    int ans=0;
    for(int i=L;i<=R;i++){
        ans+=possible[i];
    }
    cout<<ans;
}
int get_func(int a){
    isvisit[a]=true;
    int plus=0;
    int mul=1;
    int t=a;
    while(t>0){
        int temp=t%10;
        plus+=temp;
        mul*=temp;
        t/=10;
    }
    int ans=mix_num(plus,mul);
    if(ans>100000)
        return possible[a]=-1;
    if(ans==a)
        return possible[ans]=1;
    else{
        if(!isvisit[ans]){
            return possible[a]=get_func(ans);
        }
        else{
            return possible[a]=possible[ans];
        }
    }
}
int mix_num(int a,int b){
    int c=b;
    if(b==0){
        return a*10+0;
    }
    while(b>0){
        b/=10;
        a*=10;
    }
    return a+c;
}