#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
int N,M;
set<string> keyword;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        keyword.insert(temp);
    }
    for(int i=0;i<M;i++){
        cin>>temp;
        int start_idx=0;
        for(int j=0;j<temp.size();j++){
            if(temp[j]==','){
                string word=temp.substr(start_idx,j-start_idx);
                auto iter=keyword.find(word);
                if(iter!=keyword.end()){
                    keyword.erase(iter);
                }
                start_idx=j+1;
            }
        }
        string word=temp.substr(start_idx,temp.size()-start_idx);
        auto iter=keyword.find(word);
        if(iter!=keyword.end()){
            keyword.erase(iter);
        }
        cout<<keyword.size()<<'\n';
    }
    
}
