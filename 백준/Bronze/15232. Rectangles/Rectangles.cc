#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int A,B;
    cin>>A>>B;
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
            cout<<'*';
        }
        cout<<'\n';
    }

}
