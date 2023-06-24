#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int num[3];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i=0;i<3;i++){
        cin>>num[i];
    }
    sort(num,num+3);
    cout<<num[1];
   
}



