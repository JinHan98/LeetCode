#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
int T;
int x,y,r,xx,yy,rr;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>x>>y>>r>>xx>>yy>>rr;
        double d=sqrt(pow(abs((double)x-(double)xx),2)+pow(abs((double)y-(double)yy),2));
        if(d==0){
            if(r==rr){
                cout<<-1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
            continue;
        }
        if(abs(r-rr)<d&&abs(r+rr)>d){
            cout<<2<<'\n';
        }
        else if(abs(r-rr)==d||abs(r+rr)==d){
            cout<<1<<'\n';
        }
        else if(abs(r-rr)>d||abs(r+rr)<d){
            cout<<0<<'\n';
        }
    }
    
}