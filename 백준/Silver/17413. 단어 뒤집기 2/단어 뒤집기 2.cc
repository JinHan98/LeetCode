#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
string N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    getline(cin,N);
    int N_size=N.size();
    string temp;
    for(int i=0;i<N_size;i++){
        if(N[i]=='<'){
            if(temp!=""){
                reverse(temp.begin(),temp.end());
                cout<<temp;
                temp="";
            }
            for(int j=i+1;j<N_size;j++){
                if(N[j]=='>'){
                    cout<<N.substr(i,j-i+1);
                    i=j;
                    temp="";
                    break;
                }
            }
        }
        else if(N[i]==' '){
            reverse(temp.begin(),temp.end());
            cout<<temp<<' ';
            temp="";
        }
        else{
            temp.push_back(N[i]);
        }
    }
    reverse(temp.begin(),temp.end());
    cout<<temp<<' ';
}