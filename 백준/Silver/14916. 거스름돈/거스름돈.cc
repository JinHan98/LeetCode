#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int num[100001];
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    num[2]=1;
    num[4]=2;
    num[5]=1;
    num[6]=3;
    for(int i=7;i<=100000;i++){
        if(num[i-2]!=0&&num[i-5]!=0)
            num[i]=min(num[i-2],num[i-5]);
        else
            num[i]=max(num[i-2],num[i-5]);
        num[i]++;
    }
    cin>>N;
    if(num[N]!=0)
        cout<<num[N];
    else
        cout<<-1;
}
