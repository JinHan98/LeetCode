#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int cake[1001];
int people[1001];
int L,N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ex_ans;
    int ex_val=0;
    int ans=0;
    int ans_val=0;
    cin>>L>>N;
    int st,ed;
    for(int i=0;i<N;i++){
        cin>>st>>ed;
        if(ed-st>ex_val){
            ex_val=ed-st;
            ex_ans=i+1;
        }
        for(int j=st;j<=ed;j++){
            if(cake[j]==0){
                cake[j]=i+1;
                people[i+1]++;
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(people[i]>ans_val){
            ans_val=people[i];
            ans=i;
        }
    }
    cout<<ex_ans<<'\n'<<ans;
}



