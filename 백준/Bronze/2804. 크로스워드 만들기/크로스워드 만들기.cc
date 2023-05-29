#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char map[30][30];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++)
            map[i][j]='.';
    }
    string A,B;
    cin>>A>>B;
    int A_size,B_size;
    A_size=A.size();
    B_size=B.size();
    for(int i=0;i<A_size;i++){
        for(int j=0;j<B_size;j++){
            if(A[i]==B[j]){
                for(int k=0;k<A_size;k++){
                    map[j][k]=A[k];
                }
                for(int k=0;k<B_size;k++){
                    map[k][i]=B[k];
                }
                for(int a=0;a<B_size;a++){
                    for(int b=0;b<A_size;b++){
                        cout<<map[a][b];
                    }
                    cout<<'\n';
                }
                exit(0);
            }
        }
    }
    
}
// 1 2
// 2 4
// 3 6
// 4 9
// 5 12
// 6 16