#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<P>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());

	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < n; i++) {
		if (pq.size() < arr[i].first) {
			pq.push(arr[i].second);
		}
		else {
			if (pq.top() < arr[i].second) {
				pq.pop();
				pq.push(arr[i].second);
			}
		}
	}
	int sum = 0;
	while (!pq.empty())	{
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}