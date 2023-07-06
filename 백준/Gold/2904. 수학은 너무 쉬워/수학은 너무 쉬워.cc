#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <unordered_map>
#include <cmath>
using namespace std;
int N;
bool sosu[1000001];
vector<int> so;
void che();
int num[100];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int gcd=1,ans=0;
    int mx_idx=0;
    cin>>N;
    che();
    int sosu_count=so.size();
    vector<int> many(sosu_count);
    for(int i=0;i<N;i++){
        cin>>num[i];
        int A=num[i];
        int idx=0;
        while(A>1){
            if(A%so[idx]==0){
                A/=so[idx];
                many[idx]++;
            }
            else
                idx++;
        }
        if(idx>mx_idx)
            mx_idx=idx;
    }
    vector<int> gcd_arr(sosu_count);
    vector<int> check_list;
    for(int i=0;i<=mx_idx;i++){
        if(many[i]/N!=0){
            gcd*=pow(so[i],(many[i]/N));
            gcd_arr[i]=many[i]/N;
        }
    }
    for(int i=0;i<N;i++){
        vector<int> temp_many=gcd_arr;
        int A=num[i];
        int idx=0;
        while(A>1){
            if(A%so[idx]==0){
                A/=so[idx];
                temp_many[idx]--;
            }
            else
                idx++;
        }
        for(int j=0;j<=mx_idx||j<=idx;j++){
            if(temp_many[j]>0)
                ans+=temp_many[j];
        }
    }
    cout<<gcd<<' '<<ans;
}
void che(){
    int i=2;
    while(i<=1000000){
        if(!sosu[i]){
            so.push_back(i);
            for(int j=i;j<=1000000;j+=i){
                sosu[j]=true;
            }
            i++;
        }
        else
            i++;
    }
}