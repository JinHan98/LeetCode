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
    string a;
    int b,c;
    while(1){
        cin>>a>>b>>c;
        if(a=="#")
            break;
        cout<<a<<' ';
        if(b>17||c>=80)
            cout<<"Senior\n";
        else
            cout<<"Junior\n";
    }
}