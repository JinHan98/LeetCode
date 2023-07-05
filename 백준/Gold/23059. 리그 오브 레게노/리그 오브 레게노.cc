#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
int in_digree[400001];
vector<int> order[400001];
vector<int> a[400001];
unordered_map<int,string> hsh;
unordered_map<string,int> xhsh;
int ans;
int N;
bool cmp(int a, int b){
    return hsh[a]<hsh[b];
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int all_size=0;
    vector<pair<string,string> >item(N);
    for(int i=0;i<N;i++){
        cin>>item[i].first>>item[i].second;
        auto iter=xhsh.find(item[i].first);
        if(iter==xhsh.end()){
            xhsh.insert({item[i].first,all_size});
            hsh.insert({all_size++,item[i].first});
        }
        iter=xhsh.find(item[i].second);
        if(iter==xhsh.end()){
            xhsh.insert({item[i].second,all_size});
            hsh.insert({all_size++,item[i].second});
        }
        int a=xhsh[item[i].first];
        int b=xhsh[item[i].second];
        order[a].push_back(b);
        in_digree[b]++;
    }
    int index=0;
    int ct=0;
    queue<pair<int,int> > k;
    for(int i=0;i<all_size;i++){
        if(in_digree[i]==0){
            a[0].push_back(i);
            k.push({i,0});
        }
    }
    for(int i=0;i<all_size;i++){
        if(k.empty()){
            cout<<-1;
            return 0;
        }
        pair<int,int> temp;
        temp=k.front();
        k.pop();
        for(int i=0;i<order[temp.first].size();i++){
            in_digree[order[temp.first][i]]--;
            if(in_digree[order[temp.first][i]]==0){
                k.push({order[temp.first][i],temp.second+1});
                a[temp.second+1].push_back(order[temp.first][i]);
                ct=temp.second+1;
            }
        }
    }
    for(int i=0;i<=ct;i++){
        sort(a[i].begin(),a[i].end(),cmp);
        for(int j=0;j<a[i].size();j++){
            cout<<hsh[a[i][j]]<<'\n';
        }
    }
}