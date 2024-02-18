#include<iostream>
#include<algorithm>
using namespace std;
string arr[5];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int mx_idx=0;
    for(int i=0;i<5;i++){
        cin>>arr[i];
        if(arr[i].size()>mx_idx)
            mx_idx=arr[i].size();
    }
    for(int i=0;i<mx_idx;i++){
        for(int j=0;j<5;j++){
            if(arr[j].size()>i){
                cout<<arr[j][i];
            }
        }
    }
}