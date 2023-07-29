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
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            cout<<' ';
        }
        for(int k=i;k<=N;k++)
            cout<<"*";
        cout<<'\n';
    }
}