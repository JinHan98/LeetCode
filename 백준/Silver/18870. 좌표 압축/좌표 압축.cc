#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,temp;
    cin>>N;
    vector<int> num(N);
    vector<int> sor(N);
    for(int i=0;i<N;i++){
        cin>>temp;
        sor[i]=temp;
        num[i]=temp;
    }
    sort(sor.begin(),sor.end());
    sor.erase(unique(sor.begin(),sor.end()),sor.end());
    for(int i=0;i<N;i++){
        int begin=0;
        int end=sor.size();
        int mid;
        while(begin<=end){
            mid=(begin+end)/2;
            if(sor[mid]<num[i]){
                begin=mid+1;
            }
            else if(sor[mid]>num[i])
                end=mid-1;
            else{
                num[i]=mid;
                begin=end+1;
            }
        }

    }
    for(int i=0;i<N;i++){
        cout<<num[i]<<' ';
    }


}