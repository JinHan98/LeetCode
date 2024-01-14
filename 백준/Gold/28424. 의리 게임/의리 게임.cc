#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N,Q;
long long mx_al[100001];
long long now_drink[100001];
long long next_person[100001];
void uion(int a,int b);
int find(int a);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>Q;
    for(int i=1;i<=N;i++)
        cin>>mx_al[i];
    for(int i=1;i<=N+1;i++){
        next_person[i]=i;
    }
    int c,number,lt;
    for(int i=0;i<Q;i++){
        cin>>c;
        if(c==1){
            cin>>number>>lt;
            find(number);
            number=next_person[number];
            while(lt>0){
                if(number==N+1)
                    break;
                if(number!=next_person[number]){
                    number=find(number);
                    continue;
                }
                if(mx_al[number]-now_drink[number]<=lt){
                    lt-=(mx_al[number]-now_drink[number]);
                    now_drink[number]=mx_al[number];
                    uion(number,number+1);
                    number++;
                    if(number==N+1)
                        break;
                }
                else{
                    now_drink[number]+=lt;
                    lt=0;
                }
            }
        }
        else{
            cin>>number;
            find(number);
            if(number!=next_person[number]){
                cout<<mx_al[number]<<'\n';
            }
            else{
                cout<<now_drink[number]<<'\n';
            }
        }
    }
    
}
int find(int a){
    if(a==next_person[a])
        return a;
    else
        return next_person[a]=find(next_person[a]);
}
void uion(int a,int b){
    a=find(a);
    b=find(b);
    next_person[a]=next_person[b];
}