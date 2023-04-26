#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
string PPAP;
string bomb;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>PPAP>>bomb;
    string temp;
    int sz=PPAP.size();
    for(int i=0;i<sz;i++){
        temp.push_back(PPAP[i]);
        if(temp.size()>=bomb.size()){
            while(1){
                if(temp.substr(temp.size()-bomb.size())==bomb){
                    for(int j=0;j<bomb.size();j++)
                        temp.pop_back();
                }
                else
                    break;
                if(temp.size()<=bomb.size())
                    break;
            }
        }
    }
    if(temp.empty()){
        cout<<"FRULA";
    }
    else
        cout<<temp;
}
