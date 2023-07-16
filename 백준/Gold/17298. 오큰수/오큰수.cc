#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;
int num[1000000];
int ans[1000000];
void DFS(int x,int y);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>num[i];
    ans[N-1]=-1;
    stack<int> st;
    st.push(num[N-1]);
    for(int i=N-2;i>=0;i--){
        if(st.empty()){
            ans[i]=-1;
            st.push(num[i]);
            continue;
        }
        if(num[i]<st.top()){
            ans[i]=st.top();
            st.push(num[i]);
        }
        else{
            st.pop();
            i++;
        }
    }
    for(int i=0;i<N;i++)
        cout<<ans[i]<<' ';
}