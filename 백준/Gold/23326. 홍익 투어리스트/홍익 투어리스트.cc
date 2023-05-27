#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int N,Q;
set<int> famous;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int position=1;
    cin>>N>>Q;
    bool temp;
    for(int i=1;i<=N;i++){
        cin>>temp;
        if(temp){
            famous.insert(i);
        }
    }
    int op,num;
    for(int i=0;i<Q;i++){
        cin>>op;
        if(op==1){
            cin>>num;
            auto iter=famous.find(num);
            if(iter!=famous.end()){
                famous.erase(iter);
            }
            else{
                famous.insert(num);
            }
        }
        else if(op==2){
            cin>>num;
            position+=num;
            position%=N;
            if(position==0){
                position=N;
            }
        }
        else{
            if(famous.empty()){
                cout<<-1<<'\n';
                continue;
            }
            auto iter =famous.lower_bound(position);
            if(iter==famous.end()){
                cout<<*famous.begin()+N-position<<'\n';
            }
            else{
                cout<<*iter-position<<'\n';
            }
        }
    }
}