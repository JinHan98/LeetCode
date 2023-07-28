#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
int T,N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        priority_queue<int, vector<int>,greater<int> > big;
        priority_queue<int> small;
        cin>>N;
        if(N%2==1)
            cout<<N/2+1<<'\n';
        else
            cout<<N/2<<'\n';
        int num;
        for(int j=0;j<N;j++){
            cin>>num;
            if(j%2==0){//홀수 번째
                if(big.empty()&&small.empty()){
                    big.push(num);
                    small.push(num);
                    cout<<num<<' ';
                }
                else{
                    if(num<small.top()){
                        small.push(num);
                    }
                    else if(num>big.top()){
                        big.push(num);
                    }
                    else{
                        if(small.size()>big.size()){
                            big.push(num);
                        }
                        else
                            small.push(num);
                    }
                    while(small.size()!=big.size()){
                        if(small.size()>big.size()){
                            small.pop();
                            big.push(small.top());
                        }
                        else{
                            big.pop();
                            small.push(big.top());
                        }
                    }
                    cout<<small.top()<<' ';
                    if((j-18)%20==0)
                        cout<<'\n';
                }
            }
            else{//짝수 번째
                if(num<small.top()){
                    small.push(num);
                }
                else if(num>big.top()){
                    big.push(num);
                }
                else{
                    if(small.size()>big.size()){
                        big.push(num);
                    }
                    else
                        small.push(num);
                }
            }
        }
        cout<<'\n';
    }
}