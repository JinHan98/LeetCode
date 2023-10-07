#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;
int H,W,N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>H>>W>>N>>M;
    int x=1;
    int y=1;
    H--;
    W--;
    x+=(H/(N+1));
    y+=(W/(M+1));
    cout<<x*y;
   
}
//1964