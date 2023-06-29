#include <iostream>
#include <vector>

using namespace std;

bool sosu(int a);

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,temp;
    int ans=0;
    int ind=0;
    vector<int>so(1000000);
    cin>>N;
    for(int i=1;i<=N;i++){
        if(sosu(i)==1){
            so[ind]=i;
            ind++;
        }
    }
    int start=0;
    int end=0;
    temp=so[0];
    while(start<=end&&end<ind){
        if(temp<N){
            temp+=(so[++end]);
        }
        else if(temp==N){
            ans++;
            temp+=(so[++end]);
        }
        else{
            temp-=(so[start++]);
        }
    }
    cout<<ans;
}
bool sosu(int a){
    if(a==1)
        return false;
    else if(a==2)
        return true;
    if(a%2==0)
        return false;
    else {
        for(int i=3;i*i<=a;i+=2){
            if(a%i==0)
                return false;
        }
        return true;
    }
}