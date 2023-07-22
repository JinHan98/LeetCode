#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

string k;
string ans;
vector<int> idex;
void get_ZOAC(int start, int end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>k;
    int start=0;
    int end=k.size()-1;
    get_ZOAC(start,end);
}
void get_ZOAC(int start, int end){
    if(start>end)
        return ;
    else if(start==end){
        bool ed=false;
        for(int i=0;i<ans.size();i++){
            if(idex[i]>start){
                ans.insert(ans.begin()+i,k[start]);
                idex.insert(idex.begin()+i,start);
                ed=true;
                break;
            }
        }
        if(!ed){
            ans.push_back(k[start]);
            idex.push_back(start);
        }
        cout<<ans<<'\n';
        return ;
    }
    int idx=start;
    char val=k[start];
    for(int i=start+1;i<=end;i++){
        if(k[i]<val){
            val=k[i];
            idx=i;
        }
    }
    if(ans.empty()){
        ans.push_back(val);
        idex.push_back(idx);
    }
    else{
        bool ed=false;
        for(int i=0;i<ans.size();i++){
            if(idex[i]>idx){
                ans.insert(ans.begin()+i,val);
                idex.insert(idex.begin()+i,idx);
                ed=true;
                break;
            }
        }
        if(!ed){
            ans.push_back(val);
            idex.push_back(idx);
        }
    }
    cout<<ans<<'\n';
    get_ZOAC(idx+1,end);
    get_ZOAC(start,idx-1);
}