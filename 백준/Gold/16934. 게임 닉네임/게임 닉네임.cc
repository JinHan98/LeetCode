#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;
map<string,int> nick;
set<string> special;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string name;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>name;
        string sub_name;
        bool de=false;
        for(int j=0;j<name.size();j++){
            sub_name+=name[j];
            auto iter=special.find(sub_name);
            if(iter==special.end()){
                special.insert(sub_name);
                if(!de)
                    cout<<sub_name<<'\n';
                de=true;
            }
        }
        if(!de){
            auto iter=nick.find(name);
            if(iter==nick.end()){
                nick[name]=1;
                cout<<name<<'\n';
            }
            else{
                cout<<name<<++nick[name]<<'\n';
            }
        }
        else{
            auto iter=nick.find(name);
            if(iter==nick.end()){
                nick[name]=1;
            }
            else{
                nick[name]++;
            }
        }
    }
}