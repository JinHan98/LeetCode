#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int rest_sol=n;
    priority_queue<int> all;
    for(int i=0;i<enemy.size();i++){
        if(rest_sol>=enemy[i]){
            rest_sol-=enemy[i];
            all.push(enemy[i]);
        }
        else{
            if(k>0){
                if(!all.empty()){
                    if(enemy[i]>all.top()){
                        k--;
                        continue;
                    }
                    rest_sol+=all.top();
                    k--;
                    all.pop();
                    i--;
                }
                else{
                    k--;
                    continue;
                }
            }
            else
                return i;
        }
    }
    return enemy.size();
}