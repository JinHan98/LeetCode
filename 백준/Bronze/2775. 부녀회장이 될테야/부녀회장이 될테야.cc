#include <iostream>
using namespace std;
int main(){
    int T;
    int k;
    int n;
    int answer=1;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>k>>n;
        for(int j=1;j<k+2;j++)
            answer=answer*(k+n+1-j)/j;
        cout<<answer<<endl;
        answer=1;
    }
}