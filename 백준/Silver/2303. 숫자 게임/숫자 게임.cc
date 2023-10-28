#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<pair<int,int> >k;
    cin>>N;
    for(int i=0;i<N;i++){
        vector<int> temp(5);
        for(int j=0;j<5;j++){
            cin>>temp[j];
        }
        for(int a=0;a<5;a++){
            for(int b=a+1;b<5;b++){
                for(int c=b+1;c<5;c++){
                    int num=temp[a]+temp[b]+temp[c];
                    num%=10;
                    k.push({num,i+1});
                }
            }
        }
    }
    cout<<k.top().second;
}