#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
int ans=0;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int sand[499][499];
void toneido(int s,int e,int dir);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>sand[i][j];
        }
    }
    int start_p=N/2;
    int end_p=N/2;
    int count=1;
    int dir=0;
    int t=0;
    while(1){
        for(int i=0;i<count;i++){
            toneido(start_p,end_p,dir);
            if(start_p==0&&end_p==0)
                break;
            start_p+=dx[dir];
            end_p+=dy[dir];
        }
        if(start_p==0&&end_p==0)
            break;
        dir++;
        dir%=4;
        if(t%2==1)
            count++;
        t++;
    }
    cout<<ans;
}
void toneido(int s,int e,int dir){
    if(s+dx[dir]<0||s+dx[dir]>N-1||e+dy[dir]<0||e+dy[dir]>N-1)
        return ;
    int all_sand=sand[s+dx[dir]][e+dy[dir]];
    sand[s+dx[dir]][e+dy[dir]]=0;
    int rest_sand=all_sand;
    if(s+(dx[dir]*3)<0||e+(dy[dir]*3)<0||e+(dy[dir]*3)>N-1||s+(dx[dir]*3)>N-1){
        ans+=(all_sand/20);
    }
    else{
        sand[s+(dx[dir]*3)][e+(dy[dir]*3)]+=(all_sand/20);
    }
    rest_sand-=(all_sand/20);
    if(s+dy[dir]<0||e+dx[dir]<0||e+dx[dir]>N-1||s+dy[dir]>N-1){
        ans+=(all_sand/100);
    }
    else{
        sand[s+dy[dir]][e+dx[dir]]+=(all_sand/100);
    }
    rest_sand-=(all_sand/100);
    if(s-dy[dir]<0||e-dx[dir]<0||e-dx[dir]>N-1||s-dy[dir]>N-1){
        ans+=(all_sand/100);
    }
    else{
        sand[s-dy[dir]][e-dx[dir]]+=(all_sand/100);
    }
    rest_sand-=(all_sand/100);
    if(s+dx[dir]-dy[dir]<0||e-dx[dir]+dy[dir]<0||e-dx[dir]+dy[dir]>N-1||s+dx[dir]-dy[dir]>N-1){
        ans+=(all_sand*7/100);
    }
    else{
        sand[s+dx[dir]-dy[dir]][e+dy[dir]-dx[dir]]+=(all_sand*7/100);
    }
    rest_sand-=(all_sand*7/100);
    if(s+dx[dir]+dy[dir]<0||e+dx[dir]+dy[dir]<0||e+dx[dir]+dy[dir]>N-1||s+dx[dir]+dy[dir]>N-1){
        ans+=(all_sand*7/100);
    }
    else{
        sand[s+dx[dir]+dy[dir]][e+dy[dir]+dx[dir]]+=(all_sand*7/100);
    }
    rest_sand-=(all_sand*7/100);
    if(s+dx[dir]-dy[dir]-dy[dir]<0||e-dx[dir]+dy[dir]-dx[dir]<0||e-dx[dir]+dy[dir]-dx[dir]>N-1||s+dx[dir]-dy[dir]-dy[dir]>N-1){
        ans+=(all_sand/50);
    }
    else{
        sand[s+dx[dir]-dy[dir]-dy[dir]][e+dy[dir]-dx[dir]-dx[dir]]+=(all_sand/50);
    }
    rest_sand-=(all_sand/50);
    if(s+dx[dir]+dy[dir]+dy[dir]<0||e+dx[dir]+dy[dir]+dx[dir]<0||e+dx[dir]+dy[dir]+dx[dir]>N-1||s+dx[dir]+dy[dir]+dy[dir]>N-1){
        ans+=(all_sand/50);
    }
    else{
        sand[s+dx[dir]+dy[dir]+dy[dir]][e+dy[dir]+dx[dir]+dx[dir]]+=(all_sand/50);
    }
    rest_sand-=(all_sand/50);
    if(s+dx[dir]+dx[dir]-dy[dir]<0||e-dx[dir]+dy[dir]+dy[dir]<0||e-dx[dir]+dy[dir]+dy[dir]>N-1||s+dx[dir]-dy[dir]+dx[dir]>N-1){
        ans+=(all_sand/10);
    }
    else{
        sand[s+dx[dir]-dy[dir]+dx[dir]][e+dy[dir]-dx[dir]+dy[dir]]+=(all_sand/10);
    }
    rest_sand-=(all_sand/10);
    if(s+dx[dir]+dy[dir]+dx[dir]<0||e+dx[dir]+dy[dir]+dy[dir]<0||e+dx[dir]+dy[dir]+dy[dir]>N-1||s+dx[dir]+dy[dir]+dx[dir]>N-1){
        ans+=(all_sand/10);
    }
    else{
        sand[s+dx[dir]+dy[dir]+dx[dir]][e+dy[dir]+dx[dir]+dy[dir]]+=(all_sand/10);
    }
    rest_sand-=(all_sand/10);
    if(s+dx[dir]+dx[dir]<0||s+dx[dir]+dx[dir]>N-1||e+dy[dir]+dy[dir]<0||e+dy[dir]+dy[dir]>N-1)
        ans+=rest_sand;
    else
        sand[s+dx[dir]+dx[dir]][e+dy[dir]+dy[dir]]+=rest_sand;
}