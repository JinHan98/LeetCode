#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    pair<int,int> skill;
    priority_queue<int> k;
    int arr[5];
    for(int i=0;i<N;i++){
        cin>>skill.first>>skill.second;
        int mx=max(skill.first,skill.second);
        for(int j=0;j<5;j++){
            cin>>arr[j];
        }
        sort(arr,arr+5);
        mx+=arr[4];
        mx+=arr[3];
        k.push(mx);
    }
    cout<<k.top();
}