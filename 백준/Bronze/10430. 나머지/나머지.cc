#include <iostream>
using namespace std;
int main(){
    int A;
    cin>>A;
    int B;
    cin>>B;
    int C;
    cin>>C;
    cout<<(A+B)%C<<endl;
    cout<<((A%C) + (B%C))%C<<endl;
    cout<<(A*B)%C<<endl;
    cout<<((A%C) * (B%C))%C<<endl;
}