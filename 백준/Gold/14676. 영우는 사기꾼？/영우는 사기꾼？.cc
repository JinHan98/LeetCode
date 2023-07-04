#include <iostream>
#include <vector>

using namespace std;
int in_digree[100001];
int many[100001];
vector<int> build[100001];
int ans;
int N,M,K;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        int X,Y;
        cin>>X>>Y;
        build[X].push_back(Y);
        in_digree[Y]++;
    }
    bool lier=false;
    for(int i=0;i<K;i++){
        int op,b;
        cin>>op>>b;
        if(lier)
            continue;
        if(op==1){//건물을 짓는다면
            if(in_digree[b]!=0){
                lier=true;
                continue;
            }
            else{
                many[b]++;
                if(many[b]==1){
                    for(int j=0;j<build[b].size();j++){
                        in_digree[build[b][j]]--;
                    }
                }
            }
        }
        else{
            if(many[b]==0){
                lier=true;
                continue;
            }
            many[b]--;
            if(many[b]==0){
                for(int j=0;j<build[b].size();j++){
                    in_digree[build[b][j]]++;
                }
            }
        }
    }
    if(lier){
        cout<<"Lier!";
    }
    else
        cout<<"King-God-Emperor";

}

/*
나올 수 있는 경우의 수
있지도 않은 건물 파괴




*/