#include <iostream>
using namespace std;
int N;
int main() {
    cin>>N;
    while(N!=0){
        cout<<(N*(N+1))/2<<'\n';
        cin>>N;
    }
}