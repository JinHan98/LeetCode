#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
string st;
string S; 
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>N>>M>>S;
    st.push_back('I');
    for(int i=0;i<N;i++){
        st.push_back('O');
        st.push_back('I');
    }
    for(int i=0;i<M-st.size()+1;i++){
        bool is=false;
        for(int j=0;j<st.size();j++){
            if(S[i+j]!=st[j]){
                is=true;
                break;
            }
        }
        if(!is)
            ans++;
    }
    cout<<ans;
}