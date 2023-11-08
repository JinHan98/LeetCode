#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,temp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp;
        for(int j=0;j<temp;j++){
            cout<<'=';
        }
        cout<<'\n';
    }
}