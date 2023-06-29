#include <iostream>
using namespace std;

bool sosu(int k);

int main(){
    int k=100;
    int ans;
    while(k!=0){
        cin>>k;
        if(k==0)
            return 0;
        ans=0;
        for(int i=k+1;i<=k*2;i++){
            if(sosu(i)==1)
                ans++;
        }
        cout<<ans<<'\n';
    }
}

bool sosu(int k){
    if(k==1)
        return 0;
    else if(k==2)
        return 1;
    else if(k%2==0)
        return 0;
    else{
        for(int i=3;i*i<=k;i++){
            if(k%i==0)
                return 0;
        }
        return 1;
    }
}
