#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;
int N,X;
string hambuger;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    map<string,int> fruit;
    cin>>N;
    int num;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp>>num;
        auto iter=fruit.find(temp);
        if(iter!=fruit.end()){
            fruit[temp]+=num;
        }
        else{
            fruit[temp]=num;
        }
    }
    for(auto iter=fruit.begin();iter!=fruit.end();iter++){
        if(iter->second==5){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}