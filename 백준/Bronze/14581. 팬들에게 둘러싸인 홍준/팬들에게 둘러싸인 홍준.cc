#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;
string name;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>name;
    for(int i=0;i<9;i++){
        if(i!=4){
            cout<<":fan:";
        }
        else
            cout<<":"<<name<<":";
        if((i+1)%3==0)
            cout<<'\n';
    }
    
}