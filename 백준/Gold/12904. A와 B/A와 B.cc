#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
string S,T;
int S_size;
int T_size;
void DFS(string a,int idx);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>S>>T;
    S_size=S.size();
    T_size=T.size();
    DFS(T,T_size);
    cout<<0;
}
void DFS(string a,int idx){
    if(a==S){
        cout<<1;
        exit(0);
    }
    if(idx==S_size)
        return ;
    idx--;
    string temp=a;
    if(a.back()=='A'){
        temp.pop_back();
        DFS(temp,idx);
    }
    else{
        temp.pop_back();
        reverse(temp.begin(),temp.end());
        DFS(temp,idx);
    }
}