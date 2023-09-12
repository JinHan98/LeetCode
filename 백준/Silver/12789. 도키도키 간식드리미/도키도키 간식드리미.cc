#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
queue<int> w;
stack<int> last;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        w.push(temp);
    }
    int num=1;
    while(!w.empty()){
        if(w.front()==num){
            w.pop();
            num++;
        }
        else{
            if(!last.empty()){
                if(last.top()==num){
                    last.pop();
                    num++;
                }
                else{
                    last.push(w.front());
                    w.pop();
                }
            }
            else{
                last.push(w.front());
                w.pop();
            }
        }
    }
    while(!last.empty()){
        if(last.top()==num){
            last.pop();
            num++;
        }
        else{
            cout<<"Sad";
            return 0;
        }
    }
    cout<<"Nice";
}

