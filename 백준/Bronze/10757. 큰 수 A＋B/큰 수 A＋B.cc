#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
using namespace std;
string A,B;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    stack<char> ans;
    int carry=0;
    cin>>A>>B;
    int A_idx=A.size()-1;
    int B_idx=B.size()-1;
    while(A_idx>=0&&B_idx>=0){
        int A_val=A[A_idx--]-'0';
        int B_val=B[B_idx--]-'0';
        int val=A_val+B_val+carry;
        if(val>9){
            carry=1;
            ans.push(val-10+'0');
        }
        else{
            carry=0;
            ans.push(val+'0');
        }
    }
    if(A_idx==-1){
        while(B_idx>=0){
            int val=B[B_idx--]-'0'+carry;
            if(val>9){
                carry=1;
                ans.push(val-10+'0');
            }
            else{
                carry=0;
                ans.push(val+'0');
            }
        }
    }
    else if(B_idx==-1){
         while(A_idx>=0){
            int val=A[A_idx--]-'0'+carry;
            if(val>9){
                carry=1;
                ans.push(val-10+'0');
            }
            else{
                carry=0;
                ans.push(val+'0');
            }
        }
    }
    if(carry==1)
        ans.push('1');
    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }
}