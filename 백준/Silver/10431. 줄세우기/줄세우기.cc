#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
int P;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int height,tc;
    cin>>P;
    for(int i=0;i<P;i++){
        cin>>tc;
        int ans=0;
        deque<int> already;
        stack<int> wait;
        cin>>height;
        int max_val=height;
        already.push_back(height);
        while(already.size()<20){
            cin>>height;
            if(height>max_val){
                already.push_back(height);
                max_val=height;
            }
            else{
                while(!already.empty()){
                    if(already.front()<height){
                        wait.push(already.front());
                        already.pop_front();
                    }
                    else{
                        ans+=already.size();
                        already.push_front(height);
                        break;
                    }
                }
                while(!wait.empty()){
                    already.push_front(wait.top());
                    wait.pop();
                }
            }
        }
        cout<<tc<<' '<<ans<<'\n';
    }
    
}
