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
int N,M,L,R;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    vector<int> house(N);
    for(int i=0;i<N;i++){
        cin>>house[i];
    }
    map<int,int> info;
    for(int i=0;i<N;i++){
        info[house[i]]=i+1;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>L>>R;
        priority_queue<int,vector<int>,greater<int> > q;
        for(int j=L;j<=R;j++)
            q.push(info[j]);
        int num=L;
        for(int j=0;j<N;j++){
            if(j==q.top()-1){
                cout<<num<<' ';
                num++;
                q.pop();
            }
            else{
                cout<<house[j]<<' ';
            }
        }
        cout<<'\n';

    }

}
