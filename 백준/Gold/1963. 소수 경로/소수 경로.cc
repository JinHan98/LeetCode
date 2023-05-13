#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int T;
void BFS(int A,int B);
bool notsosu[10000];
int find_k(int a,int size,int num);
int find_k(int a);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i=2;i<10000;i++){
        if(notsosu[i])
            continue;
        int a=i;
        a+=i;
        while(a<10000){
            notsosu[a]=true;
            a+=i;
        }
    }
    cin>>T;
    int A,B;
    for(int i=0;i<T;i++){
        cin>>A>>B;
        if(A==B){
            cout<<0<<'\n';
            continue;
        }
        BFS(A,B);
    }
}
void BFS(int A,int B){
    bool isvisit[10000]={false,};
    isvisit[A]=true;
    queue<pair<int,int> > k;
    k.push({A,0});
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            for(int j=0;j<10;j++){
                int a=find_k(temp.first,i,j);
                if(a==0||isvisit[a])
                    continue;
                if(!notsosu[a]){
                    if(a==B){
                        cout<<temp.second+1<<'\n';
                        return ;
                    }
                    isvisit[a]=true;
                    k.push({a,temp.second+1});
                }
            }
        }
    }
    cout<<-1<<'\n';
    return ;
}
int find_k(int a,int size,int num){//size는 0,1,2,3
    int chun,back,ten,one;
    one=a%10;
    a/=10;
    ten=a%10;
    a/=10;
    back=a%10;
    a/=10;
    chun=a;
    int ans=0;
    if(size==0){
        if(num==one){
            return 0;
        }
        ans+=chun;
        ans*=10;
        ans+=back;
        ans*=10;
        ans+=ten;
        ans*=10;
        ans+=num;
        return ans;
    }
    else if(size==1){
        if(num==ten){
            return 0;
        }
        ans+=chun;
        ans*=10;
        ans+=back;
        ans*=10;
        ans+=num;
        ans*=10;
        ans+=one;
        return ans;
    }
    else if(size==2){
        if(num==back){
            return 0;
        }
        ans+=chun;
        ans*=10;
        ans+=num;
        ans*=10;
        ans+=ten;
        ans*=10;
        ans+=one;
        return ans;
    }
    else{
        if(num==chun||num==0){
            return 0;
        }
        ans+=num;
        ans*=10;
        ans+=back;
        ans*=10;
        ans+=ten;
        ans*=10;
        ans+=one;
        return ans;
    }

}