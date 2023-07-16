#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;


string N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    string ans;
    int count_=0;
    stack<char> k;
    for(int i=0;i<N.size();i++){
        if(N[i]=='('){
            count_++;
            k.push(N[i]);
        }
        else if(N[i]==')'){
            while(k.top()!='('){
                cout<<k.top();
                k.pop();
            }
            k.pop();
        }
        else if(N[i]=='*'||N[i]=='/'||N[i]=='+'||N[i]=='-'){
            if(k.empty()||k.top()=='('){
                k.push(N[i]);
                continue;
            }
            if((k.top()=='+'||k.top()=='-')&&(N[i]=='*'||N[i]=='/')){
                k.push(N[i]);
            }
            else{
                while(!k.empty()){
                    if(((k.top()=='+'||k.top()=='-')&&(N[i]=='*'||N[i]=='/'))||k.top()=='('){
                        break;
                    }
                    cout<<k.top();
                    k.pop();
                }
                k.push(N[i]);
            }
        }
        else{
            cout<<N[i];
        }
    }
    while (!k.empty())
    {
        cout<<k.top();
        k.pop();
    }
    
}

