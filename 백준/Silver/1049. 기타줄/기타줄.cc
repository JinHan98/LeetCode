#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
int N,M;
priority_queue<int,vector<int>,greater<int> > six;
priority_queue<int,vector<int>,greater<int> > one;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int s,o;
        cin>>s>>o;
        six.push(s);
        one.push(o);
    }
    if(N<6){
        cout<<min(six.top(),one.top()*N);
    }
    else{
        cout<<min(min((N/6)*six.top()+(N%6)*one.top(),(N/6+1)*six.top()),one.top()*N);
    }
    
}