#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int T;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    string temp;
    for(int i=0;i<T;i++){
        cin>>temp;
        bool biggest=true;
        for(int j=temp.size()-1;j>=1;j--){
            if(temp[j]<=temp[j-1]){
                continue;
            }
            else{
                priority_queue<char,vector<char>,greater<char> > pq;
                for(int k=j;k<temp.size();k++){
                    if(temp[k]>temp[j-1])
                        pq.push(temp[k]);
                }
                cout<<temp.substr(0,j-1);
                cout<<pq.top();
                string tp=temp.substr(j-1);
                sort(tp.begin(),tp.end());
                tp.erase(find(tp.begin(),tp.end(),pq.top()));
                cout<<tp;
                cout<<'\n';
                biggest=false;
                break;
            }
        }
        if(biggest)
            cout<<"BIGGEST\n";
    }
}