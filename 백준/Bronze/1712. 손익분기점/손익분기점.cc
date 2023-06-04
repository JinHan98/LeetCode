#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int A,B,C;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>A>>B>>C;
    if(C-B<=0){
        cout<<-1;
        return 0;
    }
    A/=(C-B);
    cout<<++A;
}