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
set<string> people;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    string name,status;
    for(int i=0;i<N;i++){
        cin>>name>>status;
        if(status=="enter"){
            people.insert(name);
        }
        else
            people.erase(name);
    }
    for(auto iter=people.rbegin();iter!=people.rend();iter++){
        cout<<*iter<<'\n';
    }
}