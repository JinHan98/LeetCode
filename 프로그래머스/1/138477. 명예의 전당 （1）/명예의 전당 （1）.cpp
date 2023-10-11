#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int,vector<int>,greater<int>> tv;
    for(int i=0;i<score.size();i++){
        if(i<k){
            tv.push(score[i]);
            answer.push_back(tv.top());
        }
        else{
            if(score[i]>tv.top()){
                tv.pop();
                tv.push(score[i]);
            }
            answer.push_back(tv.top());
        }
    }
    return answer;
}