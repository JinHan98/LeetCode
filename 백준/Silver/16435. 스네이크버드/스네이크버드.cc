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
priority_queue<int,vector<int>,greater<int> > k;
int N,num;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>num;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        k.push(temp);
    }
    while (!k.empty())
    {
        if(k.top()<=num){
            k.pop();
            num++;
        }
        else{
            cout<<num;
            return 0;
        }
    }
    cout<<num;
}