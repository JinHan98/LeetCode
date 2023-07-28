#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    unordered_set<string> pwd;
    string mingyun;
    for(int i=0;i<N;i++){
        cin>>mingyun;
        if(pwd.find(mingyun)==pwd.end()){
            pwd.insert(mingyun);
            reverse(mingyun.begin(),mingyun.end());
            if(pwd.find(mingyun)==pwd.end()){
                pwd.insert(mingyun);
            }
            else{
                cout<<mingyun.size()<<' ';
                cout<<mingyun[mingyun.size()/2];
            }
        }
        else{
            cout<<mingyun.size()<<' ';
            cout<<mingyun[mingyun.size()/2];
        }
    }
}