#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
int CCW(int x1,int y1, int x2, int y2, int x3,int y3);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int ans=CCW(x1,y1,x2,y2,x3,y3);
    if(ans==0){
        cout<<0;
    }
    else if(ans>0){
        cout<<1;
    }
    else
        cout<<-1;

}
int CCW(int x1,int y1, int x2, int y2, int x3,int y3){
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}