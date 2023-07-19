#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,P;
stack<int> line[7];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>P;
    int l,num;
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>num>>l;
        if(line[num].empty()){
            line[num].push(l);
            ans++;
        }
        else{
            if(line[num].top()>l){
                bool fil=false;
                while(line[num].top()>l){
                    line[num].pop();
                    ans++;
                    if(line[num].empty()){
                        fil=true;
                        break;
                    }
                }
                if(fil){
                    ans++;
                    line[num].push(l);
                }
                else{
                    if(line[num].top()!=l){
                        line[num].push(l);
                        ans++;
                    }
                }
            }
            else if(line[num].top()==l)
                continue;
            else{
                line[num].push(l);
                ans++;
            }
        }
    }
    cout<<ans;
}