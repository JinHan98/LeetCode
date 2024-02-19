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
stack<int> k;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int op,num;
    for(int i=0;i<N;i++){
        cin>>op;
        if(op==1){
            cin>>num;
            k.push(num);
        }
        else if(op==2){
            if(k.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<k.top()<<'\n';
                k.pop();
            }
        }
        else if(op==3){
            cout<<k.size()<<'\n';
        }
        else if(op==4){
            if(k.empty()){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        else{
            if(k.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<k.top()<<'\n';
            }
        }
    }
}