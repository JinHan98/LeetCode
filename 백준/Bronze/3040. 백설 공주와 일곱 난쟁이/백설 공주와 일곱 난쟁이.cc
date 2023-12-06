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
int num[9];
string s;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int sum=0;
    for(int i=0;i<9;i++){
        cin>>num[i];
        sum+=num[i];
    }
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            if(sum-num[i]-num[j]==100){
                for(int k=0;k<9;k++){
                    if(k!=i&&k!=j){
                        cout<<num[k]<<'\n';
                    }
                }
                return 0;
            }
        }
    }
}