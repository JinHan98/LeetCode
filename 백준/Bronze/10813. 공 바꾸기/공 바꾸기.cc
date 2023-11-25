#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    vector<int> ball(N+1);
    for(int i=1;i<=N;i++){
        ball[i]=i;
    }
    cin>>M;
    int f,s;
    for(int i=0;i<M;i++){
        cin>>f>>s;
        int temp=ball[f];
        ball[f]=ball[s];
        ball[s]=temp;
    }
    for(int i=1;i<=N;i++){
        cout<<ball[i]<<' ';
    }
}