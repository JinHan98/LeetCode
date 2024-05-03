#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    int odd=0,even=0;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        if(temp%2==1){
            odd++;
        }
        else
            even++;
    }
    if(even>odd){
        cout<<"Happy";
    }
    else{
        cout<<"Sad";
    }
}