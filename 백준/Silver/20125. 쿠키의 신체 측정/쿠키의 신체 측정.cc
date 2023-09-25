#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
int N;
int ans[5];
char body[1000][1000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>body[i][j];
        }
    }
    for(int i=1;i<N-1;i++){
        for(int j=1;j<N-1;j++){
            if(body[i][j]=='*'&&body[i+1][j]=='*'&&body[i-1][j]=='*'&&body[i][j+1]=='*'&&body[i][j-1]=='*'){
                for(int k=j-1;k>=0;k--){
                    if(body[i][k]=='*')
                        ans[0]++;
                    else
                        break;
                }
                for(int k=j+1;k<N;k++){
                    if(body[i][k]=='*')
                        ans[1]++;
                    else
                        break;
                }
                int e_w_x;
                int e_w_y=j;
                for(int k=i+1;k<N;k++){
                    if(body[k][j]=='*')
                        ans[2]++;
                    else{
                        e_w_x=k;
                        break;
                    }
                }
                for(int k=e_w_x;k<N;k++){
                    if(body[k][e_w_y-1]=='*')
                        ans[3]++;
                    else
                        break;
                }
                for(int k=e_w_x;k<N;k++){
                    if(body[k][e_w_y+1]=='*')
                        ans[4]++;
                    else
                        break;
                }
                cout<<i+1<<' '<<j+1<<'\n';
                break;
            }
        }
    }
    for(int i=0;i<5;i++)
        cout<<ans[i]<<' ';
}
