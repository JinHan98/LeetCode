#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int num=2;
    while(N!=1){
        if(N%num==0){
            cout<<num<<'\n';
            N/=num;
        }
        else
            num++;
    }
}


