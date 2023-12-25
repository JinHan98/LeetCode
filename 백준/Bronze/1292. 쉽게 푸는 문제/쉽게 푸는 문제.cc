#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int num[1001];
int acc[1001];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int idx=1;
    for(int i=1;idx<=1000;i++){
        for(int j=0;j<i;j++){
            if(idx==1001)
                break;
            num[idx++]=i;
        }
    }
    acc[0]=0;
    for(int i=1;i<=1000;i++){
        acc[i]=acc[i-1]+num[i];
    }
    int A,B;
    cin>>A>>B;
    cout<<acc[B]-acc[A-1];
    
}