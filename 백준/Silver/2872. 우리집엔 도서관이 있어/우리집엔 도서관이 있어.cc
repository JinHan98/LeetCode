#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int num[300000];
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int ans=0;
    int current_num=N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    for(int i=N-1;i>=0;i--){
        if(num[i]==current_num){
            current_num--;
        }
        else{
            ans++;
        }
    }
    cout<<ans;
}
