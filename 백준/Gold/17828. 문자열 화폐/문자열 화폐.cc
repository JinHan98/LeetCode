#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    long long X;
    cin>>N>>X;
    if(N*26<X||N>X){
        cout<<'!';
        return 0;
    }
    long long rest=X-N;
    for(int i=0;i<N;i++){
        if(rest==(N-i)*25){
            cout<<'Z';
            rest-=25;
        }
        else if((rest<(N-i)*25)&&(rest>(N-i-1)*25)){
            cout<<(char)('A'+(rest-(N-i-1)*25));
            rest-=(rest-(N-i-1)*25);
        }
        else{
            cout<<'A';
        }
    }
}