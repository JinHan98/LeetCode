#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
string sound;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>sound;
    int idx=0;
    while(idx<sound.size()){
        if(sound.substr(idx,3)=="100"){
            idx+=3;
            if(idx==sound.size()){
                cout<<"NOISE";
                return 0;
            }
            while(sound[idx]=='0'){
                idx++;
            }
            if(sound[idx]!='1'){
                cout<<"NOISE";
                return 0;
            }
            int sub_idx=idx;
            while(sound[idx]=='1'){
                idx++;
            }
            if(sound.substr(idx,2)=="00"&&idx-sub_idx>1){
                idx--;
            }
        }
        else if(sound.substr(idx,2)=="01"){
            idx+=2;
        }
        else{
            cout<<"NOISE";
            return 0;
        }
    }
    cout<<"SUBMARINE";
}