#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main(){
    int N;//화분의 개수
    int K;//화분의 수분
    int A;//물을 주는 화분의 수
    int B;//화분의 수분 증가량
    int answer=1;
    cin>>N>>K>>A>>B;
    vector<int> flower(N,K);
    int start_index=0;
    int small_sum=0;
    int temp=0;
    while(1){
        temp=0;
        for(int i=start_index;i<start_index+A;i++){
            flower[i]+=B;
        }
        for(int i=0;i<A;i++)
            temp+=flower[i];
        small_sum=temp;
        start_index=0;
        for(int i=A;i<flower.size();i++){
            temp=temp-flower[i-A]+flower[i];
            if(temp<small_sum){
                start_index=i-A+1;
                small_sum=temp;
            }
        }
        priority_queue<int,vector<int>, greater<int> > a;
        for(int i=0;i<flower.size();i++){
            flower[i]--;
            a.push(flower[i]);
        }
        if(a.top()==0)
            break;
        else
            answer++;
    }
    cout<<answer;
}