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
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int S=0;
    int T=0;
    int temp;
    for(int i=0;i<4;i++){
        cin>>temp;
        S+=temp;
    }
    for(int i=0;i<4;i++){
        cin>>temp;
        T+=temp;
    }
    cout<<max(S,T);
    
    
}