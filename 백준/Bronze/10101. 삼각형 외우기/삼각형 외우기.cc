#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int angle[3];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i=0;i<3;i++){
        cin>>angle[i];
    }
    sort(angle,angle+3);
    if(angle[0]+angle[1]+angle[2]!=180){
        cout<<"Error";
    }
    else{
        if(angle[0]==angle[1]&&angle[1]==angle[2]){
            cout<<"Equilateral";
        }
        else if(angle[0]!=angle[1]&&angle[1]!=angle[2]&&angle[0]!=angle[2]){
            cout<<"Scalene";
        }
        else{
            cout<<"Isosceles";
        }
    }
    
}