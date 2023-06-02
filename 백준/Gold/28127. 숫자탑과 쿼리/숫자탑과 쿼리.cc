#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int Q;
int num[100000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,d,x;
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>a>>d>>x;
        if(a>=x){
            cout<<1<<' '<<x<<'\n';
            continue;
        }
        num[1]=a;
        int last_sum;
        int sum=num[1];
        for(int j=2;j<100000;j++){
            last_sum=sum;
            num[j]=num[j-1]+d;
            sum+=num[j];
            if(sum>x){
                cout<<j<<' '<<x-last_sum<<'\n';
                break;
            }
            else if(sum==x){
                cout<<j<<' '<<num[j]<<'\n';
                break;
            }
        }
    }
}