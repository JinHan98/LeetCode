#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;
string word;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>word;
    priority_queue<string,vector<string>,greater<string> >k;
    for(int i=1;i<word.size();i++){
        for(int j=i+1;j<word.size();j++){
            string f=word.substr(0,i);
            string s=word.substr(i,j-i);
            string e=word.substr(j);
            reverse(f.begin(),f.end());
            reverse(s.begin(),s.end());
            reverse(e.begin(),e.end());
            k.push(f+s+e);
        }
    }
    cout<<k.top();
}