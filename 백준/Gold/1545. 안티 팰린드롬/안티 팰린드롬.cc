#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
string S;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>S;
    int S_size=S.size();
    int left,right;
    sort(S.begin(),S.end());
    if(S_size%2==0){
        left=S_size/2-1;
        right=S_size/2;
    }
    else{
        left=S_size/2-1;
        right=S_size/2+1;
    }
    for(int i=0;i<S_size/2;i++){
        if(S[left-i]==S[right+i]){
            if(right==S_size-1){
                cout<<-1;
                return 0;
            }
            else{
                bool ed=true;
                for(int j=right+i+1;j<S_size;j++){
                    if(S[j]!=S[right+i]){
                        swap(S[right+i],S[j]);
                        ed=false;
                        break;
                    }
                }
                if(ed){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<S;
}