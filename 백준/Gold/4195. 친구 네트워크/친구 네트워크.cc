#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
int T,F;
int join(int a,int b);
int num[200001];
int friend_num[200001];
int find(int a);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    string A,B;
    for(int i=0;i<T;i++){
        int idx=1;
        cin>>F;
        unordered_map<string,int> Freind;
        for(int i=1;i<2*F+1;i++){
            num[i]=i;
            friend_num[i]=1;
        }
        for(int i=0;i<F;i++){
            cin>>A>>B;
            if(Freind.count(A)==0){
                Freind[A]=idx++;
            }
            if(Freind.count(B)==0){
                Freind[B]=idx++;
            }
            cout<<join(Freind[A],Freind[B])<<'\n';
        }
    }
}
int join(int a,int b){
    a=find(a);
    b=find(b);
    if(num[a]!=num[b]){
        num[b]=a;
        friend_num[a]+=friend_num[b];
        friend_num[b]=1;
    }
    return friend_num[a];
}
int find(int a){
    if(a==num[a])
        return a;
    else{
         return num[a]=find(num[a]);
    }
}
