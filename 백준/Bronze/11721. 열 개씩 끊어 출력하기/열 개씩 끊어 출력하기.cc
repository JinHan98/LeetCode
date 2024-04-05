#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string s;
    cin>>s;
    int i=0;
    while(i<s.size()){
        cout<<s[i++];
        if(i%10==0)
            cout<<'\n';
    }
}
