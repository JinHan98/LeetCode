#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int> > edge) {
    int answer = 0;
    vector<int> dis(n,0);
    int temp;
    vector<bool> is_done(n,false);
    is_done[0]=true;
    vector<vector<bool> > line(n,vector<bool>(n,false));
    queue<int> qu;
    qu.push(0);
    for(int i=0;i<edge.size();i++){
        line[edge[i][0]-1][edge[i][1]-1]=true;
        line[edge[i][1]-1][edge[i][0]-1]=true;
    }
    while(!qu.empty()){
        temp=qu.front();
        for(int i=0;i<line[temp].size();i++){
            if(line[temp][i]==true&&is_done[i]!=true){
                dis[i]=dis[temp]+1;
                is_done[i]=true;
                qu.push(i);
            }
        }
        qu.pop();
    }
    for(int k=1;k<n;k++){
        if(dis[k]==dis[temp])
            answer++;
    }
    return answer;
}