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
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    deque<char> left;
    deque<char> right;
    string N;
    int M;
    cin>>N>>M;
    char choice;
    for(int i=0;i<N.size();i++){
        left.push_back(N[i]);
    }
    for(int i=0;i<M;i++){
        cin>>choice;
        if(choice=='L'){
            if(!left.empty()){
                right.push_front(left.back());
                left.pop_back();
            }
        }
        else if(choice=='D'){
            if(!right.empty()){
                left.push_back(right.front());
                right.pop_front();
            }
        }
        else if(choice=='B'){
            if(!left.empty()){
                left.pop_back();
            }
        }
        else if(choice=='P'){
            char temp;
            cin>>temp;
            left.push_back(temp);
        }
    }
    while(!left.empty()){
        cout<<left.front();
        left.pop_front();
    }
    while(!right.empty()){
        cout<<right.front();
        right.pop_front();
    }
}
