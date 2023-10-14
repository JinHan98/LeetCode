#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
#include <map>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int tri[3];
    cin>>tri[0]>>tri[1]>>tri[2];
    while(tri[0]!=0&&tri[1]!=0&&tri[2]!=0){
        sort(tri,tri+3);
        if(tri[0]+tri[1]<=tri[2]){
            cout<<"Invalid\n";
        }
        else if(tri[0]==tri[2]){
            cout<<"Equilateral\n";
        }
        else if(tri[0]!=tri[1]&&tri[1]!=tri[2]){
            cout<<"Scalene\n";
        }
        else{
            cout<<"Isosceles\n";
        }
        cin>>tri[0]>>tri[1]>>tri[2];
    }
    
}