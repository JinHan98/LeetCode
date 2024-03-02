#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
string A,B,C,D;
string ps(string a,string b);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>A>>B>>C>>D;
    A=A+B;
    C=C+D;
    cout<<ps(A,C);
}
string ps(string a,string b){
    string ans;
    int sum=0;
    int carry=0;
    int a_p=a.size()-1;
    int b_p=b.size()-1;
    while(a_p>=0||b_p>=0){
        if(a_p>=0&&b_p>=0){
            sum=a[a_p]-'0'+b[b_p]-'0'+carry;
            ans.insert(ans.begin(),sum%10+'0');
            carry=sum/10;
            a_p--;
            b_p--;
        }
        else if(a_p==-1){
            sum=b[b_p]-'0'+carry;
            ans.insert(ans.begin(),sum%10+'0');
            carry=sum/10;
            b_p--;
        }
        else if(b_p==-1){
            sum=a[a_p]-'0'+carry;
            ans.insert(ans.begin(),sum%10+'0');
            carry=sum/10;
            a_p--;
        }
        
    }
    if(carry==1){
        ans.insert(ans.begin(),'1');
    }
    return ans;
}