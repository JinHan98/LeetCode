#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int L,P;
    cin>>L>>P;
    int num=L*P;
    for(int i=0;i<5;i++){
        int temp;
        cin>>temp;
        cout<<temp-num<<' ';
    }
}