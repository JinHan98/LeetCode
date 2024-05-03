#include <iostream>
using namespace std;
typedef long double ld;

ld N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	cout << fixed;
	cout.precision(2);
	cout << N / 4;
}