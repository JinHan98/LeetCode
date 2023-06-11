#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int N,K;
int isvisit[2][500001];
void BFS(int n);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=0;i<2;i++){
        for(int j=0;j<500001;j++)
            isvisit[i][j]=-1;
    }
    if(N==K){
        cout<<0;
        return 0;
    }
    BFS(N);
}
void BFS(int n){


	queue<pair<int, int> > su;
	su.push({ N,0 });

	while (!su.empty())
	{
		int cur = su.front().first;
		int t = su.front().second;
		su.pop();

		if (cur > 500000 || cur < 0)
		{
			continue;
		}

		if (isvisit[t % 2][cur] != -1)
		{
			continue;
		}

		isvisit[t % 2][cur] = t;
		su.push({ cur - 1,t + 1 });
		su.push({ cur + 1,t + 1 });
		su.push({ 2 * cur , t + 1 });
	}

	for (int i = 0; i < 500000; i++)
	{
		int nk = K + ((i*(i+1))/2);
		if (nk > 500000)
		{
			break;
		}

		if (isvisit[i % 2][nk] != -1 && isvisit[i % 2][nk] <= i)
		{
			
			cout << i << endl;
			return ;
		}
	}
	cout << -1 << endl;

	return ;
}