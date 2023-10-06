#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<bool> isvisit;
int DFS(int start,int not_count,vector<vector<int>> wires);
int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    isvisit=vector<bool>(n+1,0);
    for(int i=0;i<wires.size();i++){
        int temp;
        int x=DFS(wires[i][0],i,wires);
        int y=DFS(wires[i][1],i,wires);
        //cout<<x<<' '<<y<<'\n';
        if(x<y)
            temp=y-x;
        else
            temp=x-y;
        if(temp<answer)
            answer=temp;
    }
    return answer;
}
int DFS(int start,int not_count,vector<vector<int>> wires){
    int num=1;
    isvisit[start]=true;
    for(int i=0;i<wires.size();i++){
        if(i!=not_count){
            if(!isvisit[wires[i][1]]&&wires[i][0]==start)
                num+=DFS(wires[i][1],not_count,wires);
            if(!isvisit[wires[i][0]]&&wires[i][1]==start)
                num+=DFS(wires[i][0],not_count,wires);
        }
    }
    isvisit[start]=false;
    return num;
}