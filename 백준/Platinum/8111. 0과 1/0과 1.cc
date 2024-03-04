#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
int T,N;
bool isvisit[20001];
pair<int,char> recursive[20001];
void BFS();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        string ans;
        cin>>N;
        BFS();
        int temp=0;
        while(1){
            ans.insert(ans.begin(),recursive[temp].second);
            temp=recursive[temp].first;
            if(temp==-1)
                break;
        }
        cout<<ans<<'\n';
        for(int i=0;i<N;i++){
            isvisit[i]=false;
            recursive[i]={0,0};
        }
    }
}
void BFS(){
    queue<int> k;
    k.push(1);
    isvisit[1]=true;
    recursive[1].first=-1;
    recursive[1].second='1';
    while(!k.empty()){
        int temp=k.front();
        k.pop();
        int f=temp*10;
        f%=N;
        if(!isvisit[f]){
            recursive[f].first=temp;
            recursive[f].second='0';
            isvisit[f]=true;
            k.push(f);
            if(f==0)
                break;
        }
        int s=temp*10+1;
        s%=N;
        if(!isvisit[s]){
            recursive[s].first=temp;
            recursive[s].second='1';
            isvisit[s]=true;
            k.push(s);
            if(s==0)
                break;
        }
    }
}