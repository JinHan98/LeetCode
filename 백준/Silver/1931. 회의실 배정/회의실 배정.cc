#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>&a, pair<int, int>&b) {
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    int ans=0;
    cin>>N;
    vector<pair<int,int> > a(N);
    for(int i=0;i<N;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),compare);
    int temp=a[0].second;
    ans++;
    for(int i=1;i<N;i++){
        if(a[i].first>=temp){
            temp=a[i].second;
            ans++;
        }
    }
    cout<<ans;
}