#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string S;
int a[26];
int T;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>S;
        int s_size=S.size();
        vector<int> k;
        for(int j=0;j<s_size;j++){
            a[S[j]-'A']++;
        }
        while(a[20]>0){
            k.push_back(4);
            a[20]--;
            a[5]--;
            a[14]--;
            a[17]--;
        }
        while(a[5]>0){
            k.push_back(5);
            a[5]--;
            a[8]--;
            a[21]--;
            a[4]--;
        }
        while (a[22]>0)
        {
            k.push_back(2);
            a[22]--;
            a[19]--;
            a[14]--;
        }
        while (a[6]>0)
        {
            k.push_back(8);
            a[6]--;
            a[4]--;
            a[8]--;
            a[7]--;
            a[19]--;
        }
        while (a[7]>0)
        {
            k.push_back(3);
            a[4]-=2;
            a[19]--;
            a[7]--;
            a[17]--;
        }
        while (a[25]>0)
        {
            k.push_back(0);
            a[25]--;
            a[4]--;
            a[17]--;
            a[14]--;
        }
        while (a[23]>0)
        {
            k.push_back(6);
            a[23]--;
            a[18]--;
            a[8]--;
        }
        while (a[18]>0)
        {
            k.push_back(7);
            a[18]--;
            a[4]-=2;
            a[21]--;
            a[13]--;
        }
        while (a[8]>0)
        {
            k.push_back(9);
            a[8]--;
            a[4]--;
            a[13]--;
        }
        while (a[14]>0)
        {
            k.push_back(1);
            a[14]--;
            a[13]--;
            a[4]--;
        }
        sort(k.begin(),k.end());
        int k_size=k.size();
        cout<<"Case #"<<i+1<<": ";
        for(int j=0;j<k_size;j++){
            cout<<k[j];
        }
        cout<<'\n';
    }
}
