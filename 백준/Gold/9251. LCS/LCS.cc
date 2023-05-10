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
    int A_size=A.size();
    int B_size=B.size();
    for(int i=0;i<A_size;i++){
        for(int j=0;j<B_size;j++){
            if(A[i]==B[j]){
                DP[i+1][j+1]=DP[i][j]+1;
            }
            else{
                DP[i+1][j+1]=max(DP[i][j+1],DP[i+1][j]);
            }
        }
    }
    cout<<DP[A_size][B_size];
}