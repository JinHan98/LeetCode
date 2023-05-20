#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
bool isvisit[201][201][201];
int ans[201];
int idx=0;
int A,B,C;
void DFS(int A_many,int B_many,int C_many);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>A>>B>>C;
    DFS(0,0,C);
    sort(ans,ans+idx);
    for(int i=0;i<idx;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
void DFS(int A_many,int B_many,int C_many){
    if(isvisit[A_many][B_many][C_many])
        return ;
    isvisit[A_many][B_many][C_many]=true;
    if(A_many==0){
        ans[idx++]=C_many;
    }
    if(C_many!=0){
        if(A-A_many<C_many){
            DFS(A,B_many,C_many-(A-A_many));
        }
        else{
            DFS(A_many+C_many,B_many,0);
        }
        if(B<B_many+C_many){
            DFS(A_many,B,C_many-(B-B_many));
        }
        else{
            DFS(A_many,B_many+C_many,0);
        }
    }
    if(B_many!=0){
        if(A<A_many+B_many){
            DFS(A,B_many-(A-A_many),C_many);
        }
        else{
            DFS(A_many+B_many,0,C_many);
        }
        if(C<B_many+C_many){
            DFS(A_many,B-(C-C_many),C_many);
        }
        else{
            DFS(A_many,0,B_many+C_many);
        }
    }
    if(A_many!=0){
        if(C<A_many+C_many){
            DFS(A-(C-C_many),B_many,C);
        }
        else{
            DFS(0,B_many,A_many+C_many);
        }
        if(B<B_many+A_many){
            DFS(A_many-(B-B_many),B,C_many);
        }
        else{
            DFS(0,B_many+A_many,C_many);
        }
    }
}