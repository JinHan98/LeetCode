#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int num[50];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    if(N==1){
        cout<<'A';
        return 0;
    }
    else if(N==2){
        if(num[0]==num[1]){
            cout<<num[0];
        }
        else{
            cout<<'A';
        }
        return 0;
    }
    int a=num[2]-num[1];
    if(num[1]-num[0]!=0){
        if(a%(num[1]-num[0])!=0){
            cout<<'B';
            return 0;
        }
    }
    if(num[1]-num[0]!=0)
        a/=(num[1]-num[0]);
    else{
        for(int i=1;i<N;i++){
            if(num[i]!=num[i-1]){
                cout<<'B';
                return 0;
            }
        }
        cout<<num[0];
        return 0;
    }
    int b=num[1]-(a*num[0]);
    for(int i=2;i<N;i++){
        if(num[i-1]*a+b!=num[i]){
            cout<<'B';
            return 0;
        }
    }
    cout<<num[N-1]*a+b;
}