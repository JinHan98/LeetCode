#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
string cy;
int DP[2][5001];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>cy;
    int size=cy.size();
    if(cy=="0"||cy[0]=='0'){
        cout<<0;
        return 0;
    }
    if(size>1&&cy.substr(0,2)=="00"){
        cout<<0;
        return 0;
    }
    DP[0][1]=1;
    for(int i=2;i<=size;i++){
        if(cy.substr(i-2,2)=="00"){
            cout<<0;
            return 0;
        }
        if(cy[i-1]=='0'){
            if(cy[i-2]>'2'){
                cout<<0;
                return 0;
            }
            DP[1][i]=DP[0][i-1];
            DP[1][i]%=1000000;
            continue;
        }
        DP[0][i]=DP[0][i-1]+DP[1][i-1];
        DP[0][i]%=1000000;
        if(cy[i-1]!='0'){
            if(stoi(cy.substr(i-2,2))<=26){
                DP[1][i]=DP[0][i-1];
                DP[1][i]%=1000000;
            }
        }
    }
    int ans=DP[0][size]+DP[1][size];
    cout<<ans%1000000;
}