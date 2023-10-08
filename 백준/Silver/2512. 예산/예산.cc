#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
#include <map>
using namespace std;
int N;
int yesan[10000];
int total;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>N;
    int sum=0;
    for(int i=0;i<N;i++){
        cin>>yesan[i];
        sum+=yesan[i];
        if(yesan[i]>ans)
            ans=yesan[i];
    }
    cin>>total;
    if(sum<=total){
        cout<<ans;
        return 0;
    }
    else{
        sort(yesan,yesan+N);
        if(total<yesan[0]*N){
            cout<<total/N;
            return 0;
        }
        total-=(yesan[0]*N);
        ans=yesan[0];
        for(int i=0;i<N;i++){
            yesan[i]-=ans;
        }
        int f_idx=1;
        int acc=0;
        while(total>0){
            if(yesan[f_idx]*(N-f_idx)<=total){
                total-=(yesan[f_idx]*(N-f_idx));
                ans+=yesan[f_idx];
                acc+=yesan[f_idx];
                f_idx++;
                yesan[f_idx]-=acc;
            }
            else{
                int i=1;
                while(1){
                    if(i*(N-f_idx)>total){
                        cout<<ans+i-1;
                        return 0;
                    }
                    i++;
                }
            }
        }
        cout<<ans;
    }

}
