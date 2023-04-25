#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int T;
int A,B;
bool isvisit[10000];
string order[10000];
void BFS();
void make_string(int a);
int re[4];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>A>>B;
        BFS();
        for(int j=0;j<10000;j++){
            isvisit[j]=false;
            order[j]="";
        }
    }
}
void BFS(){
    queue<int> k;
    k.push(A);
    isvisit[A]=true;
    while(!k.empty()){
        int temp=k.front();
        k.pop();
        make_string(temp);
        int tmp;
        if(temp==0)
            tmp=9999;
        else
            tmp=temp-1;
        if(!isvisit[tmp]){
            k.push(tmp);
            isvisit[tmp]=true;
            order[tmp]=order[temp]+'S';
            if(tmp==B){
                cout<<order[tmp]<<'\n';
                return ;
            }
        }
        tmp=temp*2;
        tmp%=10000;
        if(!isvisit[tmp]){
            k.push(tmp);
            isvisit[tmp]=true;
            order[tmp]=order[temp]+'D';
            if(tmp==B){
                cout<<order[tmp]<<'\n';
                return ;
            }
        }
        tmp=re[1]*1000+re[2]*100+re[3]*10+re[0];
        if(!isvisit[tmp]){
            k.push(tmp);
            isvisit[tmp]=true;
            order[tmp]=order[temp]+'L';
            if(tmp==B){
                cout<<order[tmp]<<'\n';
                return ;
            }
        }
        tmp=re[3]*1000+re[0]*100+re[1]*10+re[2];
        if(!isvisit[tmp]){
            k.push(tmp);
            isvisit[tmp]=true;
            order[tmp]=order[temp]+'R';
            if(tmp==B){
                cout<<order[tmp]<<'\n';
                return ;
            }
        }

    }
}
void make_string(int a){
    int k=3;
    for(int i=0;i<4;i++){
        re[i]=0;
    }
    while(a>0){
        re[k--]=a%10;
        a/=10;
    }
}