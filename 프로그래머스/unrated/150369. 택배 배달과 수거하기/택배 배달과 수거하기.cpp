#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    vector<int> d_val;
    vector<int> p_val;
    int d_idx=n-1;
    int p_idx=n-1;
    while(1){
        bool ed=true;
        int sum=cap;
        int idx;
        for(int i=d_idx;i>=0;i--){
            if(deliveries[i]!=0){
                d_val.push_back(i+1);
                idx=i;
                ed=false;
                break;
            }
        }
        if(ed)
            break;
        for(int i=idx;i>=0;i--){
            if(deliveries[i]>sum){
                deliveries[i]-=sum;
                d_idx=i;
                break;
            }
            else{
                sum-=deliveries[i];
                deliveries[i]=0;
            }
        }
    }
    while(1){
        bool ed=true;
        int sum=cap;
        int idx;
        for(int i=p_idx;i>=0;i--){
            if(pickups[i]!=0){
                p_val.push_back(i+1);
                idx=i;
                ed=false;
                break;
            }
        }
        if(ed)
            break;
        for(int i=idx;i>=0;i--){
            if(pickups[i]>sum){
                pickups[i]-=sum;
                p_idx=i;
                break;
            }
            else{
                sum-=pickups[i];
                pickups[i]=0;
            }
        }
    }
    for(int i=0;i<d_val.size()||i<p_val.size();i++){
        if(i<d_val.size()&&i<p_val.size()){
            answer+=(max(d_val[i],p_val[i])*2);
        }
        else{
            if(d_val.size()>p_val.size()){
                answer+=(d_val[i]*2);
            }
            else{
                answer+=(p_val[i]*2);
            }
        }
    }
    
    return answer;
}