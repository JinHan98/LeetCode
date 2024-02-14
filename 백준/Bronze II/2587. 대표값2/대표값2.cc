#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
using namespace std;
int arr[5];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int sm=0;
    for(int i=0;i<5;i++){
        cin>>arr[i];
        sm+=arr[i];
    }
    cout<<sm/5<<'\n';
    sort(arr,arr+5);
    cout<<arr[2];
}