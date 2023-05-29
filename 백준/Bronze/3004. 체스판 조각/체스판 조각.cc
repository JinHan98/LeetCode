#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    if(N%2==0){
        int temp=N/2;
        cout<<(temp+1)*(temp+1);
    }
    else{
        int temp=N/2;
        cout<<(temp+1)*(temp+2);
    }
}