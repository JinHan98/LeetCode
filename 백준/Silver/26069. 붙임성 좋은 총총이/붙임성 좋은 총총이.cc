#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    unordered_set<string> dance;
    dance.insert("ChongChong");
    cin>>N;
    string p1,p2;
    for(int i=0;i<N;i++){
        cin>>p1>>p2;
        auto iter1=dance.find(p1);
        auto iter2=dance.find(p2);
        if(iter1==dance.end()&&iter2==dance.end()){
            continue;
        }
        dance.insert(p1);
        dance.insert(p2);
    }
    cout<<dance.size();
}