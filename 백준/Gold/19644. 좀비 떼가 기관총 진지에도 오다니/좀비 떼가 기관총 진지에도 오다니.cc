#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,ML,MK,C;
bool isshot[3000001];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    queue<int> zombie;
    int temp;
    cin>>N>>ML>>MK>>C;
    for(int i=0;i<N;i++){
        cin>>temp;
        zombie.push(temp);
    }
    int many=0;
    int idx=0;
    while(!zombie.empty()){
        temp=zombie.front();
        if(temp<=MK*(many+1)){
            many++;
            isshot[idx]=true;
            if(idx>=ML-1){
                many-=isshot[idx-ML+1];
            }
            idx++;
        }
        else{
            C--;
            if(C<0){
                cout<<"NO";
                return 0;
            }
            if(idx>=ML-1){
                many-=isshot[idx-ML+1];
            }
            idx++;
        }
        zombie.pop();
    }
    cout<<"YES";
}