#include <iostream>
#include <algorithm>
using namespace std;
int arr[3];
int main() {
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    sort(arr,arr+3);
    cout<<arr[1];
}