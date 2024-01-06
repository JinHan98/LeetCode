#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int N,L;
int main(){
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	cin>>N>>L;
	deque<pair<int,int> > k;
	int ans;
	int temp;
	cin>>ans;
	k.push_back({ans,0});
	cout<<ans<<' ';
	for(int i=1;i<N;i++){
		cin>>temp;
		while(!k.empty()&&k.back().first>temp){
			k.pop_back();
		}
		k.push_back({temp,i});
		while(k.front().second<=i-L){
			k.pop_front();
		}
		cout<<k.front().first<<' ';
	}
	
}