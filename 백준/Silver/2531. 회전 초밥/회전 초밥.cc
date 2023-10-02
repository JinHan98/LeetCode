#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
int N,d,k,c;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    deque<int> sushi;
    cin>>N>>d>>k>>c;
    vector<int> many(d+1);
    deque<int> last;
    int ans=0;
    int current=0;
    int temp;
    for(int i=0;i<k;i++){
        cin>>temp;
        sushi.push_back(temp);
        last.push_back(temp);
        many[temp]++;
        if(many[temp]==1){
            current++;
        }
    }
    if(many[c]==0)
        ans=current+1;
    else
        ans=current;
    for(int i=k;i<N;i++){
        cin>>temp;
        sushi.push_back(temp);
        if(many[sushi.front()]==1)
            current--;
        many[sushi.front()]--;
        sushi.pop_front();
        many[temp]++;
        if(many[temp]==1){
            current++;
        }
        if(many[c]==0)
            current++;
        if(current>ans)
            ans=current;
        if(many[c]==0)
            current--;
    }
    for(int i=0;i<k-1;i++){
        sushi.push_back(last.front());
        last.pop_front();
        if(many[sushi.front()]==1)
            current--;
        many[sushi.front()]--;
        sushi.pop_front();
        many[sushi.back()]++;
        if(many[sushi.back()]==1){
            current++;
        }
        if(many[c]==0)
            current++;
        if(current>ans)
            ans=current;
        if(many[c]==0)
            current--;
    }
    cout<<ans;
}
