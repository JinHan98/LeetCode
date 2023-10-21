#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int sec=0;
    int mi=0;
    int temp;
    for(int i=0;i<4;i++){
        cin>>temp;
        sec+=temp;
    }
    mi=sec/60;
    sec%=60;
    cout<<mi<<'\n'<<sec<<'\n';
    
}