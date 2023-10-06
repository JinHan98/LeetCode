#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<bool> isvisit;
int ans=0;
void DFS(int tired,int depth,int idx,vector<vector<int>> dungeons);
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    isvisit=vector<bool>(dungeons.size(),false);
    for(int i=0;i<dungeons.size();i++){
        DFS(k,1,i,dungeons);
        isvisit[i]=false;
    }
    answer=ans;
    return answer;
}
void DFS(int tired,int depth,int idx,vector<vector<int>> dungeons){
    isvisit[idx]=true;
    if(tired<dungeons[idx][0])
        return ;
    tired-=dungeons[idx][1];
    if(depth>ans)
        ans=depth;
    for(int i=0;i<dungeons.size();i++){
        if(!isvisit[i]){
            DFS(tired, depth+1, i, dungeons);
            isvisit[i]=false;
        }
    }
}