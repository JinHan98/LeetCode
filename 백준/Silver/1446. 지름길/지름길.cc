#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
#include <map>
using namespace std;
int D;
int solution(int N,vector<vector<int> > road);
void DFS(int val,int current_point,int N,int num,vector<vector<int> > road);
int min_val;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N>>D;
    min_val=D;
    vector<vector<int> > road(N,vector<int>(3,0));
    for(int i=0;i<N;i++){
        cin>>road[i][0]>>road[i][1]>>road[i][2];
    }
    sort(road.begin(),road.end());
    cout<<solution(N,road);
}
int solution(int N,vector<vector<int> > road){
    for(int i=0;i<N;i++){
        if(road[i][1]<=D&&road[i][1]-road[i][0]>road[i][2])
            DFS(road[i][2]+road[i][0],road[i][1],N,i,road);
    }
    return min_val;
}
void DFS(int val,int current_point,int N,int num,vector<vector<int> > road){
    for(int i=num+1;i<N;i++){
        if(current_point<=road[i][0]&&road[i][1]-road[i][0]>road[i][2]&&road[i][1]<=D){
            DFS(val+road[i][2]+(road[i][0]-current_point),road[i][1],N,i,road);
        }
    }
    if(current_point<D){
        val+=(D-current_point);
    }
    if(val<min_val){
        min_val=val;
    }
}

