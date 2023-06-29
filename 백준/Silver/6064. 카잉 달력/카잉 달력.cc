#include <iostream>
#include <queue>

using namespace std;

bool isvisit[100001];
int gcd(int a,int b);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T,M,N,x,y,ans,temp,y_1;
    bool check;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>M>>N>>x>>y;
        if(x==y){
            cout<<x<<'\n';
            continue;
        }
        y_1=x%N;
        check=false;
        ans=x;
        temp=gcd(M,N);
        while(1){
            if(y_1==0)
                y_1=N;
            if(y_1==y){
                cout<<ans<<'\n';
                check=true;
                break;
            }
            y_1=(y_1+M)%N;
            if(ans>M*N/temp)
                break;
            ans+=M;
        }
        if(!check)
            cout<<-1<<'\n';
    }
}
int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}