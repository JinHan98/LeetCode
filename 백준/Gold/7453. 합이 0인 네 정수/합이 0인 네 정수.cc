#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N;
long long A[4000],B[4000],C[4000],D[4000];
vector<long long>A_p_B;
vector<long long>C_p_D;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A_p_B.push_back(A[i]+B[j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            C_p_D.push_back(C[i]+D[j]);
        }
    }
    sort(A_p_B.begin(),A_p_B.end());
    sort(C_p_D.begin(),C_p_D.end());
    for(int i=0;i<A_p_B.size();i++){
        long long num=-A_p_B[i];
        int l_index=lower_bound(C_p_D.begin(),C_p_D.end(),num)-C_p_D.begin();
        int u_index=upper_bound(C_p_D.begin(),C_p_D.end(),num)-C_p_D.begin();
        if(num==C_p_D[l_index])
            ans+=(u_index-l_index);
    }
    cout<<ans;
}