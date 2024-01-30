#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
int N;
pair<int,int> coor[10000];
double CCW(double x1,double y1, double x2, double y2, double x3,double y3);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>coor[i].first>>coor[i].second;
    }
    double ans=0.00;
    for(int i=1;i<N;i++){
        ans+=CCW(coor[0].first,coor[0].second,coor[i-1].first,coor[i-1].second,coor[i].first,coor[i].second);
    }
    ans=abs(ans)/2;
    cout.precision(1);
    cout<<fixed;
    cout<<ans;
}
double CCW(double x1,double y1, double x2, double y2, double x3,double y3){
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}