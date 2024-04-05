#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string s;
    while(s!="END"){
        getline(cin,s);
        if(s=="END")
            break;
        reverse(s.begin(),s.end());
        cout<<s<<'\n';
    }
}
