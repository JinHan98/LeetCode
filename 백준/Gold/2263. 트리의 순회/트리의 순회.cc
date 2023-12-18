#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int N;
vector<int> in_order;
vector<int> post_order;
void merge(int i_start, int i_end,int p_start,int p_end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    in_order=vector<int>(N);
    post_order=vector<int>(N);
    for(int i=0;i<N;i++){
        cin>>in_order[i];
    }
    for(int i=0;i<N;i++){
        cin>>post_order[i];
    }
    int idx;
    merge(0,N-1,0,N-1);

}
void merge(int i_start, int i_end,int p_start,int p_end){
    if(i_start>i_end)
        return ;
    else if(i_start==i_end){
        cout<<in_order[i_start]<<' ';
        return;
    }
    int idx;
    for(int i=i_start;i<=i_end;i++){
        if(in_order[i]==post_order[p_end]){
            idx=i;
            break;
        }
    }
    cout<<in_order[idx]<<' '; 
    merge(i_start,idx-1,p_start,p_start+idx-1-i_start);
    merge(idx+1,i_end,p_end-1-i_end+idx+1,p_end-1);
}