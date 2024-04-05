#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int A,B;
    cin>>A>>B;
    while(A!=0&&B!=0){
        if(B%A==0){
            cout<<"factor\n";
        }
        else if(A%B==0){
            cout<<"multiple\n";
        }
        else{
            cout<<"neither\n";
        }
        cin>>A>>B;
    }
}
