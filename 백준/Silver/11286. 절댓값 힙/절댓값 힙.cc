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
struct compare
{
    bool operator()(int a,int b){
        if(abs(a)==abs(b)){
            return a>b;
        }
        else{
            return abs(a)>abs(b);
        }
    }
};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<int,vector<int>,compare>k;
    int N;
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        if(temp!=0){
            k.push(temp);
        }
        else{
            if(!k.empty()){
                cout<<k.top()<<'\n';
                k.pop();
            }
            else
                cout<<0<<'\n';
        }
    }
    
}