#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;

string boolean;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int seq=1;
    while(1){
        cin>>boolean;
        if(boolean=="()")
            break;
        int temp=0;
        int depth=0;
        for(int i=0;i<boolean.size();i++){
            if(boolean[i]=='('){
                temp++;
                if(temp>depth){
                    depth=temp;
                }
            }
            else if(boolean[i]==')')
                temp--;

        }
        temp=0;
        stack<char> k;
        for(int i=0;i<boolean.size();i++){
            if(boolean[i]=='('){
                k.push(boolean[i]);
                temp++;
            }
            else if(boolean[i]==')'){
                bool a=true;
                if(k.top()=='F'){
                    a=false;
                }
                k.pop();
                while(k.top()!='('){
                    bool b=true;
                    if(k.top()=='F')
                        b=false;
                    if(depth%2==temp%2){//AND
                        a=a&b;
                    }
                    else
                        a=a|b;
                    k.pop();
                }
                k.pop();
                temp--;
                if(a)
                    k.push('T');
                else
                    k.push('F');
            }
            else
                k.push(boolean[i]);
        }
        if(k.top()=='F'){
            cout<<seq<<". "<<"false\n";
        }
        else{
            cout<<seq<<". "<<"true\n";
        }
        seq++;
    }
    
}

