#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
long long X,Y;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>X>>Y;
    long long Z=Y*100/X;
    if(X==Y||Z==99){
        cout<<-1;
        return 0;
    }
    long long temp;
    long long temp2;
    int mid;
    int s=1;
    int e=1000000000;
    while(1){
        mid=(s+e)/2;
        temp=(Y+mid)*100/(X+mid);
        temp2=(Y+mid-1)*100/(X+mid-1);
        if(temp!=temp2&&temp2==Z){
            cout<<mid;
            return 0;
        }
        if(temp>Z){
            e=mid-1;
        }
        else
            s=mid+1;
    }
}