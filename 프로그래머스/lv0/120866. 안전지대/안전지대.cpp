#include <string>
#include <vector>

using namespace std;
int dx[8]={1,0,-1,1,-1,1,0,-1};
int dy[8]={1,1,1,0,0,-1,-1,-1};
int solution(vector<vector<int>> board) {
    vector<vector<bool>>unsafe(board.size(),vector<bool>(board.size(),false));
    int answer = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==1){
                unsafe[i][j]=true;
                for(int k=0;k<8;k++){
                    if(i+dx[k]<0||i+dx[k]>board.size()-1||j+dy[k]<0||j+dy[k]>board.size()-1)
                        continue;
                    unsafe[i+dx[k]][j+dy[k]]=true;
                }
            }
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(unsafe[i][j]==false)
                answer++;
        }
    }
    return answer;
}