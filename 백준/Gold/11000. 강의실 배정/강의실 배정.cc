#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int,vector<int>,greater<int> > s;
priority_queue<int,vector<int>,greater<int> > e;

int main(){
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int N,tp1,tp2;

	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tp1>>tp2;
		s.push(tp1);
		e.push(tp2);
	}
	int ans=0;
	int temp=0;
	while(!s.empty()&&!e.empty()){
		if(s.top()<e.top()){
			s.pop();
			temp++;
			if(temp>ans)
				ans=temp;
		}
		else if(s.top()==e.top()){
			s.pop();
			e.pop();
		}
		else{
			e.pop();
			temp--;
		}
	}
	cout<<ans;
}