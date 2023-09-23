#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
string password;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1){
        cin>>password;
        if(password=="end"){
            break;
        }
        bool ispass=true;
        bool ismoem=false;
        int acc_moem=0;
        int acc_zaem=0;
        char last=password[0];
        if(password[0]=='a'||password[0]=='e'||password[0]=='i'||password[0]=='o'||password[0]=='u'){
            ismoem=true;
            acc_moem++;
        }
        else
            acc_zaem++;
        for(int i=1;i<password.size();i++){
            if(password[i]=='a'||password[i]=='e'||password[i]=='i'||password[i]=='o'||password[i]=='u'){
                ismoem=true;
                acc_moem++;
                acc_zaem=0;
                if(acc_moem>2){
                    ispass=false;
                    break;
                }
            }
            else{
                acc_moem=0;
                acc_zaem++;
                if(acc_zaem>2){
                    ispass=false;
                    break;
                }
            }
            if(password[i]==password[i-1]){
                if(password[i]!='e'&&password[i]!='o'){
                    ispass=false;
                    break;
                }
            }
            last=password[i];
        }
        if(ispass&&ismoem){
            cout<<'<'<<password<<'>'<<" is acceptable.\n";
        }
        else
            cout<<'<'<<password<<'>'<<" is not acceptable.\n";
    }
    
}
