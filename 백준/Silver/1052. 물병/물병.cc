#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
int N,K;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    int num=N;
    while(1){
        int c_num=num;
        int count=0;
        while(c_num!=0){
            if(c_num&1)
                count++;
            c_num/=2;
        }
        if(count<=K){
            cout<<num-N<<'\n';
            return 0;
        }
        num++;
    }

    
}