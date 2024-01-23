#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string A;
    cin>>A;
    string B=A;
    reverse(A.begin(),A.end());
    for(int i=0;i<A.size();i++){
        if(A[i]!=B[i]){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    return 0;
}