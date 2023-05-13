#include <iostream>
#include <string>
#include <queue>
using namespace std;
char len[50][50];
int numlen[50][50];
int group[51];
int N;
void join(int a,int b);
int make_num(char k);
int find(int a);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        group[i]=i;
    }
    int ans=0;
    priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > >k;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            vector<int> temp(3);
            cin>>len[i][j];
            numlen[i][j]=make_num(len[i][j]);
            temp[0]=numlen[i][j];
            temp[1]=i;
            temp[2]=j;
            k.push(temp);
        }
    }
    while(!k.empty()){
        vector<int> temp;
        temp=k.top();
        if(temp[1]==temp[2]){
            ans+=temp[0];
        }
        else{
            if(temp[0]==0){
                k.pop();
                continue;
            }
            find(temp[1]);
            find(temp[2]);
            if(group[temp[1]]==group[temp[2]]){
                ans+=temp[0];
            }
            else{
                join(temp[1],temp[2]);
            }
        }
        k.pop();
    }
    for(int i=0;i<N;i++){
        if(find(i)!=0){
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
    return 0;

}
int make_num(char k){
    if(k=='0'){
        return 0;
    }
    if(k>='A'&&k<='Z'){
        return k-'A'+27;
    }
    else{
        return k-'a'+1;
    }
}
int find(int a){
    if(a==group[a])
        return a;
    else{
        return group[a]=find(group[a]);
    }
}
void join(int a,int b){
    a=find(a);
    b=find(b);
    if(a>b){
        group[a]=group[b];
    }
    else{
        group[b]=group[a];
    }
}