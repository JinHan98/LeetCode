#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,M;
int num[15000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    sort(num,num+N);
    int s_pointer=0;
    int e_pointer=N-1;
    while(s_pointer<e_pointer){
        int mid=num[s_pointer]+num[e_pointer];
        if(mid<M){
            s_pointer++;
        }
        else if(mid>M){
            e_pointer--;
        }
        else{
            ans++;
            s_pointer++;
            e_pointer--;
        }
    }
    cout<<ans;
    return 0;
}