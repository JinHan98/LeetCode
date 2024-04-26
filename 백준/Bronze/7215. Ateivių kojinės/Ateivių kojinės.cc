#include <iostream>
#include <algorithm>
using namespace std;
int N,K;
int num[1000];
int main() {
    cin>>N>>K;
    for(int i=0;i<K;i++){
        cin>>num[i];
    }
    bool fail=true;
    for(int i=0;i<K;i++){
        if(num[i]>=N){
            fail=false;
            break;
        }
    }
    if(fail){
        cout<<-1;
        return 0;
    }
    int ans=0;
    for(int i=0;i<K;i++){
        if(num[i]>=N){
            ans+=(N-1);
        }
        else{
            ans+=num[i];
        }
    }
    cout<<++ans;
}