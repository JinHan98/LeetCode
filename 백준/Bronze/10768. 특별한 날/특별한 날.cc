#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int m,d;
    cin>>m>>d;
    if(m==2&&d==18){
        cout<<"Special";
    }
    else if((m==2&&d<18)||m<2){
        cout<<"Before";
    }
    else{
        cout<<"After";
    }
}