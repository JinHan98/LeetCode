#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


int N,P,W,L,G;
map<string,int> hacking;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>P>>W>>L>>G;
    int point=0;
    string name;
    char op;
    bool iron=false;
    for(int i=0;i<P;i++){
        cin>>name>>op;
        if(op=='W')
            hacking[name]=W;
        else
            hacking[name]=-L;
    }
    for(int i=0;i<N;i++){
        cin>>name;
        if(iron)
            continue;
        auto iter=hacking.find(name);
        if(iter!=hacking.end()){
            point+=hacking[name];
            if(point<0)
                point=0;
            else if(point>=G)
                iron=true;
        }
        else{
            point-=L;
            if(point<0)
                point=0;
        }
    }
    if(!iron)
        cout<<"I AM IRONMAN!!";
    else
        cout<<"I AM NOT IRONMAN!!";
}
/*
absolute 2 3 4 의  합으로 표현 자릿수 홀수
chiken number or starcraft number, and 합성수 , 소인수 짝수




*/