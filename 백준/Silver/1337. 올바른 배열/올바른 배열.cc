#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int num[50];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    sort(num,num+N);
    for(int i=0;i<N;i++){
        int temp=0;
        for(int j=i+1;j<N;j++){
            if(num[j]-num[i]>4){
                break;
            }
            else{
                temp++;
            }
        }
        if(temp>ans){
            ans=temp;
        }
    }
    cout<<4-ans;
}