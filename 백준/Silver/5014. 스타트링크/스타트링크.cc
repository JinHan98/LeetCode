#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int F,S,G,U,D;
bool isvisit[1000001];
void BFS(int start);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>F>>S>>G>>U>>D;
    BFS(S);    
}
void BFS(int start){
    queue<pair<int,int> > k;
    pair<int,int> temp;
    isvisit[start]=true;
    k.push(make_pair(start,0));
    while(!k.empty()){
        temp=k.front();
        k.pop();
        if(temp.first==G){
            cout<<temp.second;
            return ;
        }
        if(temp.first+U<=F&&!isvisit[temp.first+U]){
            k.push(make_pair(temp.first+U,temp.second+1));
            isvisit[temp.first+U]=true;
        }
        if(temp.first-D>=1&&!isvisit[temp.first-D]){
            k.push(make_pair(temp.first-D,temp.second+1));
            isvisit[temp.first-D]=true;
        }
    }
    cout<<"use the stairs";
    return ;
}