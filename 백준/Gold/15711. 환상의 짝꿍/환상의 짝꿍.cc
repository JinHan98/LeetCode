#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
long long A,B,C;
bool num[2000001];
vector<int> k;
bool issosu(long long a);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=2;i<=2000000;i++){
        if(!num[i]){
            k.push_back(i);
            for(int j=2;i*j<=2000000;j++){
                num[i*j]=true;
            }
        }
    }
    for(int i=0;i<T;i++){
        cin>>A>>B;
        C=A+B;
        if(C==2){
            cout<<"NO"<<'\n';
            continue;
        }
        if(C%2==0){
            cout<<"YES"<<'\n';
        }
        else{
            if(issosu(C-2)){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        }
    }
}
bool issosu(long long a){
    if(a==1)
        return 0;
    else if(a==2)
        return 1;
    if(a%2==0){
        return 0;
    }
    else{
        for(int i=1;k[i]*k[i]<=a&&i<k.size();i++){
            if(a%k[i]==0)
                return 0;
        }
        return 1;
    }
}