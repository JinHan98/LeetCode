#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
string board[505];
int dp[505][505][4];
int dx[2] = {1,0};
int dy[2] = {0,1};

// x,y에서 n-1,n-1까지 갈 때 만들 수 있는 몰라 개수, str 완성정도
int solve(int x, int y, int str){
  if (x == n-1 && y == n-1) return 0;

  int &ret = dp[x][y][str];
  if (ret != -1) return ret;
  ret = 0;

  for (int i=0; i<2; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if (nx < 0 || nx > n-1 || ny < 0 || ny > n-1) continue;

    if (board[nx][ny] == 'M'){
      ret = max(ret, solve(nx,ny,1));
    }
    else if (board[nx][ny] == 'O' && (str == 1)){
      ret = max(ret, solve(nx,ny,2));
    }
    else if (board[nx][ny] == 'L' && (str == 2)) {
      ret = max(ret, solve(nx,ny,3));
    }
    else if (board[nx][ny] == 'A' && (str == 3)){
      ret = max(ret, solve(nx,ny,0)+1);
    }
    else ret = max(ret, solve(nx,ny,0));
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n;

  for (int i=0; i<n; i++)
    cin >> board[i];

  memset(dp, -1, sizeof(dp));

  if (board[0][0] == 'M') cout << solve(0,0,1);
  else cout << solve(0,0,0);
  
}