#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        a[i]-=32;
    }
    cout<<a;
    

}
