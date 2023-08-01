#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int N,Q;
int arr[100001];
int many[10001];
set<int> order; // x에 있는 xi
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>Q;
    for(int i=1;i<=N;i++){
        int a;
        cin>>a;
        order.insert(a);
        arr[i]=a;
        many[a]++;
    }
    int op,num;
    for(int i=0;i<Q;i++){
        cin>>op>>num;
        if(op==1){
            if(N==1){
                cout<<0<<'\n';
                continue;
            }
            if(num==0){
                auto iter=order.find(0);
                if(iter!=order.end()){
                    cout<<1<<'\n';
                }
                else
                    cout<<0<<'\n';
            }
            else{
                bool a=false;
                for(int i=1;i*i<=num;i++){
                    if(num%i==0){
                        auto iter=order.find(i);
                        if(iter!=order.end()){
                            auto it=order.find(num/i);
                            if(it!=order.end()){
                                if(it==iter){
                                    if(many[*iter]>1){
                                        cout<<1<<'\n';
                                        a=true;
                                        break;
                                    }
                                }
                                else{
                                    cout<<1<<'\n';
                                    a=true;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(!a){
                    cout<<0<<'\n';
                }
            }
        }
        else{
            if(arr[num]!=0){
                order.insert(0);
                many[0]++;
                int temp=arr[num];
                arr[num]=0;
                many[temp]--;
                if(many[temp]==0){
                    order.erase(temp);
                }
            }
        }
    }
}