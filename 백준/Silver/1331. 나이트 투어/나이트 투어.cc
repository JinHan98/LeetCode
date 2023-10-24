#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;
bool isvisit[6][6];
bool is_right(string A,string val);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string start;
    string A;
    string val;
    bool isvalid=true;
    cin>>val;
    start=val;
    isvisit[val[0]-'A'][val[1]-'0']=true;
    for(int i=1;i<36;i++){
        cin>>A;
        if(!isvalid)
            continue;
        if(isvisit[A[0]-'A'][A[1]-'0']){
            isvalid=false;
            continue;
        }
        isvisit[A[0]-'A'][A[1]-'0']=true;
        if(!is_right(A,val)){
            isvalid=false;
            continue;
        }
        val=A;
    }
    if(!is_right(val,start)){
        cout<<"Invalid";
        return 0;
    }
    if(isvalid)
        cout<<"Valid";
    else
        cout<<"Invalid";
}
bool is_right(string A,string val){
    int a=A[0]-val[0];
    int b=A[1]-val[1];
    if(a<0)
        a=-a;
    if(b<0)
        b=-b;
    if(a==2&&b==1)
        return true;
    else if(b==2&&a==1)
        return true;
    else
        return false;
}