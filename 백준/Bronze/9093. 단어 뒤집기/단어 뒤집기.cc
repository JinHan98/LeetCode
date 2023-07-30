#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;
int T;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    //cin.ignore('\n');
    string a;
    for(int i=0;i<=T;i++){
        getline(cin,a);
        if(i==0)
            continue;
        int start=0;
        for(int j=0;j<a.size();j++){
            if(a[j]==' '){
                reverse(a.begin()+start,a.begin()+j);
                cout<<a.substr(start,j-start)<<' ';
                start=j+1;
            }
        }
        reverse(a.begin()+start,a.end());
        cout<<a.substr(start)<<'\n';
    }
}