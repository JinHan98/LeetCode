#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

int N;
vector<int> temp;
int DP[1000000];
int num[1000000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    DP[0]=1;
    int mx=0;
    int mx_idx=0;
    temp.push_back(num[0]);
    for(int i=1;i<N;i++){
        if(num[i]>temp.back()){
            temp.push_back(num[i]);
            DP[i]=temp.size();
            if(DP[i]>mx){
                mx=DP[i];
                mx_idx=i;
            }
        }
        else{
            int idx=lower_bound(temp.begin(),temp.end(),num[i])-temp.begin();
            DP[i]=idx+1;
            temp[idx]=num[i];
        }
    }
    cout<<temp.size();

    return 0;
    
}