#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    if(N==0){
        cout<<0;
        return 0;
    }
    int temp;
    int current=M;
    int ans=1;
    for(int i=0;i<N;i++){
        cin>>temp;
        if(current-temp>=0){
            current-=temp;
        }
        else{
            ans++;
            current=M-temp;
        }
    }
    cout<<ans;
}
// 1 2
// 2 4
// 3 6
// 4 9
// 5 12
// 6 16