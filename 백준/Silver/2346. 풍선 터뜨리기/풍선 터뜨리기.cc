#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
using namespace std;
int N;
deque<pair<int,int> > k;
vector<int> ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int temp;
    for(int i=1;i<=N;i++){
        cin>>temp;
        k.push_back({i,temp});
    }
    ans.push_back(1);
    temp=k.front().second;
    k.pop_front();
    for(int i=0;i<N-1;i++){
        if(temp>0)
            temp--;
        while(temp!=0){
            if(temp>0){
                k.push_back(k.front());
                k.pop_front();
                temp--;
            }
            else{
                k.push_front(k.back());
                k.pop_back();
                temp++;
            }
        }
        ans.push_back(k.front().first);
        temp=k.front().second;
        k.pop_front();
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]<<' ';
    }
}