#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b);
long long N;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    set<int> sosu;
    vector<bool> not_sosu(1000001,false);
    not_sosu[0]=true;
    not_sosu[1]=true;
    for(int i=2;i<=1000000;i++){
        if(!not_sosu[i]){
            sosu.insert(i);
            for(int j=i+i;j<=1000000;j+=i){
                not_sosu[j]=true;
            }
        }
    }
    while(1){
        long long ans=1;
        cin>>N;
        if(N==0)
            break;
        
        if(N==1){
            cout<<0<<'\n';
            continue;
        }
        for(auto iter=sosu.begin();iter!=sosu.end();iter++){
            if(N==1)
                break;
            else{
                int num=0;
                long long a=gcd(N,*iter);
                while(a==*iter){
                    num++;
                    N/=(*iter);
                    a=gcd(N,*iter);
                }
                if(num!=0){
                    if(num==1){
                        ans*=(*iter-1);
                    }
                    else{
                        ans*=(pow(*iter,num-1)*(*iter-1));
                    }
                }
            }
        }
        if(N!=1){
            ans*=(N-1);
            cout<<ans<<'\n';
        }
        else
            cout<<ans<<'\n';
    }
    return 0;
}
long long gcd(long long a,long long b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}