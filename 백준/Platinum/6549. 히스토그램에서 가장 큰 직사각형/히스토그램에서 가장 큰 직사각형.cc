#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

vector<long long> hist;
int N;
long long divide_conquer(int left,int right);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1){
        cin>>N;
        if(N==0)
            return 0;
        long long ans;
        hist.resize(N);
        for(int i=0;i<N;i++){
            cin>>hist[i];
        }
        ans=divide_conquer(0,N-1);
        cout<<ans<<'\n';
    }
    
}
long long divide_conquer(int left,int right){
    if(left==right)
        return hist[left];
    int mid=(left+right)/2;
    long long left_val;
    long long right_val;
    left_val=divide_conquer(left,mid);
    right_val=divide_conquer(mid+1,right);
    long long ans=max(right_val,left_val);
    int ll=mid;
    int lr=mid+1;
    long long h=min(hist[ll],hist[lr]);
    ans=max(ans,h*2);
    while(left<ll||lr<right){
        if(lr<right&&(ll==left||hist[ll-1]<hist[lr+1])){
            lr++;
            h=min(h,hist[lr]);
        }
        else{
            ll--;
            h=min(h,hist[ll]);
        }
        ans=max(ans,h*(lr-ll+1));
    }
    return ans;
}
