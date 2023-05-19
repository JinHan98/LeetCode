#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
long long DP[21][100];
int num[100];
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    cin>>num[0];
    DP[num[0]][0]++;
    for(int i=1;i<N-1;i++){
        cin>>num[i];
        for(int j=0;j<21;j++){
            if(j<=20-num[i]){
                DP[j][i]+=DP[j+num[i]][i-1];
            }
            if(j>=num[i]){
                DP[j][i]+=DP[j-num[i]][i-1];
            }
        }
    }
    int temp;
    cin>>temp;
    cout<<DP[temp][N-2];
}