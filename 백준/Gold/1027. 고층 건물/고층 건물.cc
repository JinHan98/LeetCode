#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
long long building[51];
int ans[51];
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>building[i];
    }
    for(int i=1;i<=N;i++){//시작
        for(int j=i+1;j<=N;j++){//끝
            bool ed=false;
            pair<long long,long long> a,b;//분수 first는 분모 second는 분자
            a.first=j-i;
            a.second=building[j]-building[i];
            b.first=a.first;
            b.second=a.first*building[i]-a.second*i;
            for(int k=i+1;k<j;k++){
                double val=(double)(a.second*k+b.second)/(double)a.first;
                if(val<=building[k]){
                    ed=true;
                    break;
                }
            }
            if(!ed){
                ans[i]++;ans[j]++;
            }
        }
    }
    int mx=0;
    for(int i=1;i<=N;i++){
        if(ans[i]>mx)
            mx=ans[i];
    }
    cout<<mx;
}

//ax+b=cx+d
//(a-c)x=d-b