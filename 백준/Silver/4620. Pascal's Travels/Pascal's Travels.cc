#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

char pan[100][100];
int N;
long long DP[100][100];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1){
        cin>>N;
        if(N==-1)
            break;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>pan[i][j];
            }
        }
        DP[0][0]=1;
        for(int i=0;i<N-1;i++){
            for(int j=i;j<N;j++){
                if(pan[i][j]-'0'+j<N){
                    DP[i][j+pan[i][j]-'0']+=DP[i][j];
                }
                if(pan[i][j]-'0'+i<N){
                    DP[i+pan[i][j]-'0'][j]+=DP[i][j];
                }
            }
            for(int j=i+1;j<N;j++){
                if(pan[j][i]-'0'+j<N){
                    DP[j+pan[j][i]-'0'][i]+=DP[j][i];
                }
                if(pan[j][i]-'0'+i<N){
                    DP[j][pan[j][i]-'0'+i]+=DP[j][i];
                }
            }
        }
        cout<<DP[N-1][N-1]<<'\n';
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                DP[i][j]=0;
            }
        }
    }
}
