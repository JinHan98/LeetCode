#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int N;
string numbers[100];
bool isvisit[10];
char num[3];
int ans=0;
void DFS(int val,int depth);
pair<int,int> s_b[100];
bool istrue();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>numbers[i]>>s_b[i].first>>s_b[i].second;
    }
    for(int i=1;i<=9;i++){
        DFS(i,0);
        isvisit[i]=false;
    }
    cout<<ans;
}
void DFS(int val,int depth){
    isvisit[val]=true;
    num[depth]=val+'0';
    if(depth==2){
        if(istrue())
        ans++;
        return ;
    }
    else{
        for(int i=1;i<=9;i++){
            if(!isvisit[i]){
                DFS(i,depth+1);
                isvisit[i]=false;
            }
        }
    }
}
bool istrue(){
    pair<int,int> str_bal;
    for(int i=0;i<N;i++){
        str_bal={0,0};
        for(int j=0;j<3;j++){
            if(numbers[i][j]==num[j])
                str_bal.first++;
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j!=k&&numbers[i][j]==num[k]){
                    str_bal.second++;
                }
            }
        }
        if(str_bal!=s_b[i]){
            return false;
        }
    }
    return true;
}