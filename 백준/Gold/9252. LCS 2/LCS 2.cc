#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[1001][1001];
string A,B;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>A>>B;
    string ans;
    int A_size=A.size();
    int B_size=B.size();
    for(int i=0;i<A_size;i++){
        for(int j=0;j<B_size;j++){
            if(A[i]==B[j]){
                DP[i+1][j+1]=DP[i][j]+1;
            }
            else{
                if(DP[i][j+1]>DP[i+1][j]){
                    DP[i+1][j+1]=DP[i][j+1];
                }
                else{
                    DP[i+1][j+1]=DP[i+1][j];
                }
            }
        }
    }
    while(A_size>=0&&B_size>=0){
        if(DP[A_size][B_size]==DP[A_size-1][B_size]){
            A_size--;
        }
        else if(DP[A_size][B_size]==DP[A_size][B_size-1]){
            B_size--;
        }
        else {
            A_size--;
            B_size--;
            ans.push_back(A[A_size]);
        }
    }
    A_size=A.size();
    B_size=B.size();
    cout<<DP[A_size][B_size]<<'\n';
    if(DP[A_size][B_size]!=0){
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
    
    // if(DP[A_size][B_size].second!=0)
    //     cout<<DP[A_size][B_size].first;
}