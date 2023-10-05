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
string solution(string S);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string S;
    cin>>S;
    cout<<solution(S);
}
string solution(string S){
    string ans;
    int zero=0;
    int one=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='0')
            zero++;
        else
            one++;
    }
    zero/=2;
    one/=2;
    int count_zero=0;
    int count_one=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='0'){
            if(count_zero<zero){
                ans.push_back('0');
                count_zero++;
            }
        }
        else{
            if(count_one>=one){
                ans.push_back('1');
            }
            count_one++;
        }
    }
    return ans;
}

