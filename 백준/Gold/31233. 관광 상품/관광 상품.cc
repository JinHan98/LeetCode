#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int N;
long long product[200000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>product[i];
    }
    int ans=0;
    if(N==2){
        cout<<(product[0]<product[1]?product[0]:product[1]);
        return 0;
    }
    else{
        for(int i=0;i+2<N;i++){
            vector<long long> temp(3);
            temp[0]=product[i];
            temp[1]=product[i+1];
            temp[2]=product[i+2];
            sort(temp.begin(),temp.end(),greater<int>());
            if(ans<temp[1])
                ans=temp[1];
        }
    }
    cout<<ans;
}