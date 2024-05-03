#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string line = ""; int cntLine = 0;

  while (getline(cin, line))
    cntLine++;

  cout << cntLine << "\n";

  return 0;
}