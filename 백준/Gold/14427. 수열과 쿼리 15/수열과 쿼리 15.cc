#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;
int N,M;
int num[100001];
map<int,set<int> > k;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num[i];
        k[num[i]].insert(i);
    }
    cin>>M;
    int choice;
    for(int i=0;i<M;i++){
        cin>>choice;
        if(choice==1){
            int idx,val;
            cin>>idx>>val;
            k[num[idx]].erase(idx);
            if(k[num[idx]].empty()){
                k.erase(num[idx]);
            }
            k[val].insert(idx);
            num[idx]=val;
        }
        else{
            cout<<*(k.begin()->second.begin())<<'\n';
        }
    }
}

