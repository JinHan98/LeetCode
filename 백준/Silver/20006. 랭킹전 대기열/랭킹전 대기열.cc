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
typedef struct
{
    int min_val;
    int max_val;
    map<string,int> people;
}room;

int p,m,l,n;
vector<room> rooms;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>p>>m;
    string name;
    int level;
    for(int i=0;i<p;i++){
        cin>>level>>name;
        bool end=false;
        for(int j=0;j<rooms.size();j++){
            if(rooms[j].min_val<=level&&rooms[j].max_val>=level&&rooms[j].people.size()<m){
                rooms[j].people[name]=level;
                end=true;
                break;
            }
        }
        if(end)
            continue;
        room new_room;
        new_room.max_val=level+10;
        new_room.min_val=level-10;
        new_room.people[name]=level;
        rooms.push_back(new_room);
    }
    for(int i=0;i<rooms.size();i++){
        if(rooms[i].people.size()==m){
            cout<<"Started!\n";
        }
        else{
            cout<<"Waiting!\n";
        }
        for(auto iter=rooms[i].people.begin();iter!=rooms[i].people.end();iter++){
            cout<<iter->second<<' '<<iter->first<<'\n';
        }
    }
}