#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
using namespace std;
int L,A,B,C,D;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>L>>A>>B>>C>>D;
    while(1){
        L--;
        if(L<0){
            cout<<0;
            return 0;
        }
        A-=C;
        B-=D;
        if(A<0)
            A=0;
        if(B<0)
            B=0;
        if(A==B&&B==0)
            break;
    }
    cout<<L;

}