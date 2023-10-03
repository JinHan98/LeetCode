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
map<char,int> k;
string word;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>N;
    cin>>word;
    for(int i=0;i<word.size();i++){
        auto iter=k.find(word[i]);
        if(iter!=k.end()){
            k[word[i]]++;
        }
        else
            k[word[i]]=1;
    }
    for(int j=0;j<N-1;j++){
        map<char,int> words=k;
        cin>>word;
        for(int i=0;i<word.size();i++){
            auto iter=words.find(word[i]);
            if(iter!=words.end()){
                words[word[i]]--;
                if(words[word[i]]==0){
                    words.erase(word[i]);
                }
            }
            else{
                words[word[i]]=-1;
            }
        }
        if(words.size()==0){
            ans++;
            continue;
        }
        if(words.size()==1){
            if(words.begin()->second>=-1&&words.begin()->second<=1){
                ans++;
                continue;
            }
            else
                continue;
        }
        if(words.size()>2)
            continue;
        int temp1=0;
        int temp2=0;
        for(auto iter=words.begin();iter!=words.end();iter++){
            temp2=temp1;
            temp1=iter->second;
        }
        if((temp2==-1&&temp1==1)||(temp2==1&&temp1==-1)){
            ans++;
        }
    }
    cout<<ans;
}
