#include<iostream>
#include<algorithm>
using namespace std;
int alpha[26];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    string s;
    cin.ignore();
    getline(cin,s);
    for(int i=0;i<N;i++){
       if(s[i]>='a'&&s[i]<='z')
           alpha[s[i]-'a']++;
    }
    sort(alpha,alpha+26);
    cout<<alpha[25];
}