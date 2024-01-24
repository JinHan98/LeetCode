#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
int M;
int num=0;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>M;
    string op;
    int x;
    for(int i=0;i<M;i++){
        cin>>op;
        if(op=="add"){
            cin>>x;
            if(!(num&(1<<x)))
                num+=(1<<x);
        }
        else if(op=="remove"){
            cin>>x;
            if(num&(1<<x)){
                num-=(1<<x);
            }
        }
        else if(op=="check"){
            cin>>x;
            if(num&(1<<x)){
                cout<<1<<'\n';
            }
            else
                cout<<0<<'\n';
        }
        else if(op=="toggle"){
            cin>>x;
            if(num&(1<<x)){
                num-=(1<<x);
            }
            else
                num+=(1<<x);
        }
        else if(op=="all"){
            num=0;
            for(int i=1;i<=20;i++){
                num+=(1<<i);
            }
        }
        else{
            num=0;
        }
    }
    
}