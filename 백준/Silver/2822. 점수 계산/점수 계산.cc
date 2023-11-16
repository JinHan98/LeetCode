#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<pair<int,int> > score;
    int temp;
    for(int i=0;i<8;i++){
        cin>>temp;
        score.push({temp,i+1});
    }
    int ans=0;
    vector<int> answer;
    for(int i=0;i<5;i++){
        ans+=score.top().first;
        answer.push_back(score.top().second);
        score.pop();
    }
    sort(answer.begin(),answer.end());
    cout<<ans<<'\n';
    for(int i=0;i<answer.size();i++)
        cout<<answer[i]<<' ';
}