#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    string L;
    cin>>a>>L;
    int j=0;
    vector<int> k(a);
    k[0]=0;
    for(int i=1;i<a;i++){
        while (j > 0 && L[i] != L[j])
			j = k[j - 1];
        if(L[j]==L[i]){
            k[i]=j+1;
            j++;
        }
    }
    cout<<a-j;
}