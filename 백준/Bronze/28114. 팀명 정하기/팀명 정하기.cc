#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;



pair<int,string> team[3];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int yr[3];
    for(int i=0;i<3;i++){
        cin>>team[i].first;
        cin>>yr[i];
        yr[i]%=100;
        cin>>team[i].second;
    }
    sort(yr,yr+3);
    for(int i=0;i<3;i++)
        cout<<*(yr+i);
    cout<<'\n';
    sort(team,team+3,greater<pair<int,string> >());
    for(int i=0;i<3;i++)
        cout<<team[i].second[0];
    return 0;
}