#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int solve[26];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    int svp=0;
    int time;
    char pro;
    string op;
    while(1){
        cin>>time;
        if(time==-1)
            break;
        cin>>pro>>op;
        if(op[0]=='r'){
            svp++;
            ans+=time+(solve[pro-'A']*20);
        }
        else{
            solve[pro-'A']++;
        }
    }
    cout<<svp<<'\n'<<ans;
}



