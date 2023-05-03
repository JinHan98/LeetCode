#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int max_weight = 0;
    for (int i = 0; i < n; i++) {
        if (weights[i] > max_weight + 1) {
            break;
        } else {
            max_weight += weights[i];
        }
    }
    cout << max_weight + 1;
    return 0;
}
