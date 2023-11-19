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
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    priority_queue<int> people;
    int dasom,temp;
    cin>>dasom;
    if(N==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<N;i++){
        cin>>temp;
        people.push(temp);
    }
    int ans=0;
    while(dasom<=people.top()){
        people.push(people.top()-1);
        people.pop();
        dasom++;
        ans++;
    }
    cout<<ans;
}