#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    unordered_map<string,int> poketmon;
    unordered_map<int,string> rpoketmon;
    cin>>N>>M;
    string pok;
    for(int i=1;i<=N;i++){
        cin>>pok;
        poketmon[pok]=i;
        rpoketmon[i]=pok;
    }
    for(int i=1;i<=M;i++){
        cin>>pok;
        if(pok[0]>'0'&&pok[0]<='9'){
            int p=stoi(pok);
            cout<<rpoketmon[p]<<'\n';
        }
        else
            cout<<poketmon[pok]<<'\n';
    }
    
}
