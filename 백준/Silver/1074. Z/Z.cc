#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int N,R,C;
int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};
int ans=0;
void divide(int degree, int start_x,int start_y);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>R>>C;
    divide(N,0,0);
}
void divide(int degree, int start_x,int start_y){
    if(R>start_x+pow(2,degree)||R<start_x||C>start_y+pow(2,degree)||C<start_y){
        ans+=(pow(2,degree)*pow(2,degree));
        return ;
    }
    else{
        if(degree!=1){
            divide(degree-1,start_x,start_y);
            divide(degree-1,start_x,start_y+pow(2,degree-1));
            divide(degree-1,start_x+pow(2,degree-1),start_y);
            divide(degree-1,start_x+pow(2,degree-1),start_y+pow(2,degree-1));
        }
        else{
            for(int i=0;i<4;i++){
                if(start_x+dx[i]==R&&start_y+dy[i]==C){
                    cout<<ans;
                    exit(0);
                }
                ans++;
            }
        }
    }
}
