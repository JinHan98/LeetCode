#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
string N;
string plus_one(string A);
bool carry=false;
bool ispal(string a);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int N_size=N.size();
    if(N=="9"){
        cout<<"11";
        return 0;
    }
    if(N_size==1){
        N[0]++;
        cout<<N;
        return 0;
    }
    else{
        int half=(N_size-2)/2;
        string K=N.substr(0,half+1);
        if(N_size%2==1){
            K.push_back(N[N_size/2]);
        }
        string L=K;
        string M=N.substr(0,half+1);
        reverse(M.begin(),M.end());
        K+=M;
        if(K>N){
            cout<<K;
            return 0;
        }
        L=plus_one(L);
        int L_size=L.size();
        string reverse_L=L;
        if(N_size%2==1||carry){
            reverse(reverse_L.begin(),reverse_L.end());
            L.pop_back();
            if(N_size%2==1&&carry)
                L.pop_back();
        }
        else{
            reverse(reverse_L.begin(),reverse_L.end());
        }
        L+=reverse_L;
        cout<<L;
        return 0;
    }
}
string plus_one(string A){
    int k=A.size()-1;
    while(k>=0){
        if(A[k]=='9'){
            A[k]='0';
            k--;
        }
        else{
            A[k]++;
            break;
        }
    }
    if(k==-1){
        carry=true;
        A.insert(A.begin(),'1');
    }
    return A;
}
bool ispal(string a){
    int k=a.size()-1;
    for(int i=0;i<=(k-2)/2;i++){
        if(a[i]!=a[k-i])
            return 0;
    }
    return 1;
}