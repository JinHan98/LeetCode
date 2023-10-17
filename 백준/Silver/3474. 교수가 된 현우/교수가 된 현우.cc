#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <unordered_map>
#include <cmath>
using namespace std;
int T,C;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>C;
        int two=0;
        int five=0;
        int temp=C;
        while(temp>0){
            two+=(temp/2);
            temp/=2;
        }
        temp=C;
        while(temp>0){
            five+=(temp/5);
            temp/=5;
        }
        cout<<min(two,five)<<'\n';
    }
    
}