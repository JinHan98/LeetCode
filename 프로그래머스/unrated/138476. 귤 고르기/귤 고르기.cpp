#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> count;
    for(int i=0;i<tangerine.size();i++){
        auto iter=count.find(tangerine[i]);
        if(iter!=count.end())
            count[tangerine[i]]++;
        else
            count[tangerine[i]]=1;
    }
    
    priority_queue<pair<int,int>> box;
    for(auto iter=count.begin();iter!=count.end();iter++){
        box.push({iter->second,iter->first});
    }
    while(k>0){
        answer++;
        if(box.top().first<=k){
            k-=box.top().first;
            box.pop();
        }
        else{
            break;
        }
    }
    return answer;
}