#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int arr[100];
int K, N;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>arr[i];
        q.push(arr[i]);
    }
    long long last=-1;
    long long current;
    for(int i=0;i<N;i++){
        current=q.top();
        if(current==last){
            i--;
            q.pop();
            continue;
        }
        for(int j=0;j<K;j++){
            if(current*arr[j]<pow(2,31))
                q.push(current*arr[j]);
        }
        last=current;
        q.pop();
    }
    cout<<current;
    
}
