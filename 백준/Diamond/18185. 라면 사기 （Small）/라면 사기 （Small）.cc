#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int A[3];
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>N;
    int idx=0;
    for(int i=0;i<N;i++){
        if(idx!=3)
            cin>>A[idx++];
        if(A[idx-1]==0){
            if(idx==1){
                idx=0;
                continue;
            }
            else if(idx==2){
                ans+=(3*A[0]);
                idx=0;
                continue;
            }
            else{
                if(A[0]==A[1]){
                    ans+=(5*A[0]);
                    A[0]=0;
                    A[1]=0;
                    idx=0;
                    continue;
                }
                int m=min(A[0],A[1]);
                if(m==A[0]){
                    ans+=(5*A[0]);
                    ans+=(3*(A[1]-A[0]));
                    A[0]=0;
                    A[1]=0;
                    idx=0;
                }
                else{
                    ans+=(5*A[1]);
                    ans+=(3*(A[0]-A[1]));
                    A[0]=0;
                    A[1]=0;
                    idx=0;
                }
                continue;
            }
        }
        if(idx!=3)
            continue;
        else{
            if(A[1]>A[2]){
                if(A[1]-A[2]>=A[0]){
                    ans+=(5*A[0]);
                    A[0]=A[1]-A[0];
                    A[1]=A[2];
                    A[2]=0;
                    idx=2;
                    continue;
                }
                else{
                    ans+=(5*(A[1]-A[2]));
                    A[0]-=(A[1]-A[2]);
                    A[1]=A[2];
                    idx=3;
                    i--;
                    continue;
                }
            }
            if(A[0]==A[1]&&A[1]==A[2]){
                ans+=(7*A[0]);
                A[0]=0;
                A[1]=0;
                A[2]=0;
                idx=0;
                continue;
            }
            if(A[0]==A[1]){
                if(A[2]<A[1]){
                    ans+=(7*A[2]);
                    ans+=(5*(A[0]-A[2]));
                    A[0]=0;
                    A[1]=0;
                    A[2]=0;
                    idx=0;
                    continue;
                }
                else{
                    ans+=(7*A[0]);
                    A[0]=A[2]-A[0];
                    A[1]=0;
                    A[2]=0;
                    idx=1;
                    continue;
                }
            }
            else if(A[1]==A[2]){
                if(A[1]<A[0]){
                    ans+=(7*A[1]);
                    ans+=(3*(A[0]-A[1]));
                    A[0]=0;
                    A[1]=0;
                    A[2]=0;
                    idx=0;
                    continue;
                }
                else{
                    ans+=(7*A[0]);
                    int temp=A[0];
                    A[1]-=temp;
                    A[2]-=temp;
                    A[0]=A[1];
                    A[1]=A[2];
                    A[2]=0;
                    idx=2;
                    continue;
                }
            }
            else if(A[0]==A[2]){
                if(A[0]<A[1]){
                    ans+=(5*A[0]);
                    A[0]=A[1]-A[0];
                    A[1]=A[2]-A[0];
                    A[2]=0;
                    idx=2;
                    continue;
                }
                else{
                    ans+=(7*A[1]);
                    ans+=(3*(A[0]-A[1]));
                    A[0]=A[2]-A[1];
                    A[1]=0;
                    A[2]=0;
                    idx=1;
                    continue;
                }
            }
            else{
                int m=min(A[0],A[1]);
                m=min(m,A[2]);
                if(m==A[0]){
                    ans+=(7*A[0]);
                    A[0]=A[1]-A[0];
                    A[1]=A[2]-m;
                    A[2]=0;
                    idx=2;
                }
                else if(m==A[1]){
                    ans+=(7*A[1]);
                    ans+=(3*(A[0]-A[1]));
                    A[0]=A[2]-A[1];
                    A[1]=0;
                    A[2]=0;
                    idx=1;
                }
                else{
                    ans+=(7*A[2]);
                    A[0]-=A[2];
                    A[1]-=A[2];
                    A[2]=0;
                    if(A[1]>A[0]){
                        ans+=(5*A[0]);
                        ans+=(3*(A[1]-A[0]));
                    }
                    else{
                        ans+=(5*A[1]);
                        ans+=(3*(A[0]-A[1]));
                    }
                    A[0]=0;
                    A[1]=0;
                    idx=0;
                }
            }
        }
    }
    sort(A,A+3);
    ans+=(7*A[0]);
    ans+=(5*(A[1]-A[0]));
    ans+=(3*(A[2]-A[1]));
    cout<<ans;
}