#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef struct 
{
    int bean;
    int length;
    string word;
}WORD;

struct cmp
{
    bool operator()(WORD a,WORD b){
        if(a.bean==b.bean){
            if(a.length==b.length){
                return a.word>b.word;
            }
            else
                return a.length<b.length;
        }
        else
            return a.bean<b.bean;
    }
};



int N,M;
map<string,int> word;
priority_queue<WORD,vector<WORD>,cmp> k;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    string w;
    for(int i=0;i<N;i++){
        cin>>w;
        if(w.size()<M)
            continue;
        auto iter=word.find(w);
        if(iter!=word.end()){
            word[w]++;
        }
        else
            word[w]=1;
    }
    for(auto iter=word.begin();iter!=word.end();iter++){
        WORD t;
        t.bean=iter->second;
        t.length=iter->first.size();
        t.word=iter->first;
        k.push(t);
    }
    while(!k.empty()){
        cout<<k.top().word<<'\n';
        k.pop();
    }
    
}