#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string king;
    string stone;
    string op;
    cin>>king>>stone>>N;
    pair<int,int> k_dest={king[0]-'A',king[1]-'1'};
    pair<int,int> s_dest={stone[0]-'A',stone[1]-'1'};
    for(int i=0;i<N;i++){
        cin>>op;
        pair<int,int> k_past=k_dest;
        pair<int,int> s_past=s_dest;
        for(int j=0;j<op.size();j++){
            if(op[j]=='R'){
                if(k_dest.first==7){
                    k_dest=k_past;
                    break;
                }
                k_dest.first++;
            }
            else if(op[j]=='L'){
                if(k_dest.first==0){
                    k_dest=k_past;
                    break;
                }
                k_dest.first--;
            }
            else if(op[j]=='B'){
                if(k_dest.second==0){
                    k_dest=k_past;
                    break;
                }
                k_dest.second--;
            }
            else{
                if(k_dest.second==7){
                    k_dest=k_past;
                    break;
                }
                k_dest.second++;
            }
        }
        if(k_dest==s_dest){
            bool fail=false;
            for(int j=0;j<op.size();j++){
                if(op[j]=='R'){
                    if(s_dest.first==7){
                        fail=true;
                        break;
                    }
                    s_dest.first++;
                }
                else if(op[j]=='L'){
                    if(s_dest.first==0){
                        fail=true;
                        break;
                    }
                    s_dest.first--;
                }
                else if(op[j]=='B'){
                    if(s_dest.second==0){
                        fail=true;
                        break;
                    }
                    s_dest.second--;
                }
                else{
                    if(s_dest.second==7){
                        fail=true;
                        break;
                    }
                    s_dest.second++;
                }
            }
            if(fail){
                k_dest=k_past;
                s_dest=s_past;
            }
        }
    }
    cout<<(char)(k_dest.first+'A')<<k_dest.second+1<<'\n';
    cout<<(char)(s_dest.first+'A')<<s_dest.second+1;
    
}