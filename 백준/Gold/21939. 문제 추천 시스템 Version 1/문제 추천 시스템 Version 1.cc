#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int N,M;
map<int,int> mapping;
set<int> val[101];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,d;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>n>>d;
        mapping[n]=d;
        val[d].insert(n);
    }
    cin>>M;
    string op;
    int option;
    for(int i=0;i<M;i++){
        cin>>op;
        if(op[0]=='r'){
            cin>>option;
            if(option==1){
                for(int i=100;i>=1;i--){
                    if(!val[i].empty()){
                        cout<<*(val[i].rbegin())<<'\n';
                        break;
                    }
                }
            }
            else{
                for(int i=1;i<=100;i++){
                    if(!val[i].empty()){
                        cout<<*(val[i].begin())<<'\n';
                        break;
                    }
                }
            }
        }
        else if(op[0]=='a'){
            cin>>n>>d;
            auto iter=mapping.find(n);
            if(iter==mapping.end()){
                val[d].insert(n);
            }
            else{
                int e=mapping[n];
                val[e].erase(n);
                val[d].insert(n);
            }
            mapping[n]=d;
        }
        else{
            cin>>option;
            int e=mapping[option];
            val[e].erase(option);
            mapping.erase(option);
        }
    }
}