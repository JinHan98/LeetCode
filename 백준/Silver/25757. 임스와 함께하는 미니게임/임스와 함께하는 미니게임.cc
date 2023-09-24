#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
int N;
char game;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    set<string> user;
    string temp;
    cin>>N>>game;
    for(int i=0;i<N;i++){
        cin>>temp;
        user.insert(temp);
    }
    if(game=='Y')
        cout<<user.size();
    else if(game=='F')
        cout<<user.size()/2;
    else
        cout<<user.size()/3;
    
}
