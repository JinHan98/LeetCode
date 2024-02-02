#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
using namespace std;
int A,B;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1){
        cin>>A>>B;
        if(A==0&&B==0)
            break;
        cout<<A+B<<'\n';
    }
}