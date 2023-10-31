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
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    vector<int> num(N);
    map<int,int> many;
    int av=0;
    for(int i=0;i<N;i++){
        cin>>num[i];
        av+=num[i];
        auto iter=many.find(num[i]);
        if(iter!=many.end()){
            many[num[i]]++;
        }
        else{
            many[num[i]]=1;
        }
    }
    sort(num.begin(),num.end());
    av = round((float)av / N);
    int mid=num[(N-1)/2];
    int m=0;
    int range=num[N-1]-num[0];
    int idx=-1;
    bool sec=false;
    for(auto iter=many.begin();iter!=many.end();iter++){
        if(m<=iter->second){
            if(m==iter->second&&!sec){
                idx=iter->first;
                m=iter->second;
                sec=true;
            }
            else if(m<iter->second){
                idx=iter->first;
                m=iter->second;
                sec=false;
            }
        }
    }
    cout<<av<<'\n'<<mid<<'\n'<<idx<<'\n'<<range<<'\n';
}