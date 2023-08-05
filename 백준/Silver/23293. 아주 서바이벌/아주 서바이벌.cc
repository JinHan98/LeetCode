#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int T,N;
set<int> cheating;
set<int> block;
typedef struct 
{
    int position;
    map<int,int> item;
}player;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T>>N;
    vector<player> Player(N+1);
    for(int i=1;i<=N;i++){
        Player[i].position=1;
    }
    int num,p_num,p1,p2;
    char act_code;
    for(int i=0;i<T;i++){
        cin>>num>>p_num>>act_code;
        if(act_code=='M'){
            cin>>p1;
            Player[p_num].position=p1;
        }
        else if(act_code=='F'){
            cin>>p1;
            if(Player[p_num].position!=p1){
                cheating.insert(num);
            }
            auto iter=Player[p_num].item.find(p1);
            if(iter!=Player[p_num].item.end()){
                Player[p_num].item[p1]++;
            }
            else{
                Player[p_num].item[p1]=1;
            }
            
        }
        else if(act_code=='C'){
            cin>>p1>>p2;
            auto iter=Player[p_num].item.find(p1);
            if(iter!=Player[p_num].item.end()){
                Player[p_num].item[p1]--;
                if(Player[p_num].item[p1]==0)
                    Player[p_num].item.erase(p1);
            }
            else{
                cheating.insert(num);
            }
            iter=Player[p_num].item.find(p2);
            if(iter!=Player[p_num].item.end()){
                Player[p_num].item[p2]--;
                if(Player[p_num].item[p2]==0)
                    Player[p_num].item.erase(p2);
            }
            else{
                cheating.insert(num);
            }
        }
        else{
            cin>>p1;
            if(Player[p_num].position!=Player[p1].position){
                cheating.insert(num);
                block.insert(p_num);
            }
        }
    }
    cout<<cheating.size()<<'\n';
    if(cheating.size()!=0){
        for(auto iter=cheating.begin();iter!=cheating.end();iter++){
            cout<<*iter<<' ';
        }
        cout<<'\n';
    }
    cout<<block.size()<<'\n';
    for(auto iter=block.begin();iter!=block.end();iter++){
        cout<<*iter<<' ';
    }
}