#include <iostream>
using namespace std;

int prime(int M);

int main(){
    int N,M;
    int many=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>M;
        if(prime(M)==1)
            many++;
    }
    cout<<many;
}
int prime(int M){
    if(M==2)
        return 1;
    if(M%2==0||M==1)
        return 0;
    for(int i=3;i*i<=M;i+=2){
        if(M%i==0)
            return 0;
    }
    return 1;
}