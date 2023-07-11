#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

long long messi[40];
int N;
string one_two="Messi Gimossi";
int ans=0;
void divide(int digree);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    cin>>N;
    messi[0]=5;
    messi[1]=13;
    int digree;
    int i=2;
    while(1){
        messi[i]=messi[i-1]+messi[i-2]+1;
        if(messi[i]>1073741823)
            break;
        i++;
    }
    for(int idx=0;idx<40;idx++){
        if(N<=messi[idx]){
            if(N==messi[idx]){
                cout<<'i';
                return 0;
            }
            else{
                digree=idx;
                break;
            }
        }
    }
    divide(digree);
    return 0;
}
void divide(int digree){
    if(digree==0||digree==1){
        char a=one_two[N-1];
        if(a==' '){
            cout<<"Messi Messi Gimossi";
        }
        else
            cout<<a;
    }
    else{
        N-=messi[digree-1];
        if(N==1){
            cout<<"Messi Messi Gimossi";
            exit(0);
        }
        N--;
        for(int i=0;i<40;i++){
            if(messi[i]>=N){
                if(N==messi[i]){
                    cout<<'i';
                    exit(0);
                }
                else{
                    divide(i);
                }
                break;
            }
        }
    }

}