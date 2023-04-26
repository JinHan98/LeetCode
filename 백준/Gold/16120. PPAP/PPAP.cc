#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
string PPAP;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>PPAP;
    string temp;
    int sz=PPAP.size();
    for(int i=0;i<sz;i++){
        temp.push_back(PPAP[i]);
        if(temp.size()>=4){
            while(1){
                if(temp.substr(temp.size()-4)=="PPAP"){
                    temp.pop_back();
                    temp.pop_back();
                    temp.pop_back();
                }
                else
                    break;
                if(temp.size()<=4)
                    break;
            }
        }
    }
    if(temp=="P"){
        cout<<"PPAP";
    }
    else
        cout<<"NP";
}
