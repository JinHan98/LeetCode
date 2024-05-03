#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        if(s=="Algorithm"){
            cout<<204<<'\n';
        }
        else if(s=="DataAnalysis"){
            cout<<207<<'\n';
        }
        else if(s=="ArtificialIntelligence"){
            cout<<302<<'\n';
        }
        else if(s=="CyberSecurity"){
            cout<<"B101"<<'\n';
        }
        else if(s=="Network"){
            cout<<303<<'\n';
        }
        else if(s=="Startup"){
            cout<<501<<'\n';
        }
        else{
            cout<<105<<'\n';
        }
    }
    

}