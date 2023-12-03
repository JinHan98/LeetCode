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
int alpha[26];
string s;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>s;
    for(int i=0;i<s.size();i++){
        alpha[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        cout<<alpha[i]<<' ';
    }
    
}