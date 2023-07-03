#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool isvisit[4000000];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    int temp;
    vector<int> card(M);
    for(int i=0;i<M;i++){
        cin>>card[i];
    }
    sort(card.begin(),card.end());
    for (int i = 0; i < K; i++) {
        cin>>temp;
        int it = upper_bound(card.begin(), card.end(), temp)-card.begin();
        if(!isvisit[it]){
            cout<<card[it]<<'\n';
            isvisit[it]=true;
        }
        else{
            for(int j=it+1;j<M;j++){
                if(!isvisit[j]){
                    cout<<card[j]<<'\n';
                    isvisit[j]=true;
                    break;
                }
            }
        }
    }
    return 0;
}
