#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int isprime(int i);
int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    for(int i=M;i<=N;i++){
        if(isprime(i)==1)
            cout<<i<<'\n';
    }
}
int isprime(int i){
    if(i==1)
        return 0;
    else if(i==2)
        return 1;
    else if(i%2==0&&i!=2)
        return 0;
    else{
        for(int j=3;j*j<=i;j++){
            if(i%j==0)
                return 0;
        }
        return 1;
    }
}