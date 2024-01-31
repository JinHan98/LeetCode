#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
 
ll mod = 1e17;
int n, a[101][101], dx[] = { 0,1 }, dy[] = { 1,0 };
vector<ll> d[101][101];
 
vector<ll> add(vector<ll> a, vector<ll> b) {
    if (b.size() > a.size()) swap(a, b);
    int as = a.size(), bs = b.size();
    ll m = -1;    // carry ll
    for (int i = 0; i < as; i++) {
        if (m > 0 && i) a[i] += m, m = -1;
        if (i < bs) a[i] += b[i];
        if (a[i] >= mod) m = a[i] / mod, a[i] %= mod;
    }
    if (m != -1) a.push_back(m);
    return a;
}
 
vector<ll> dp(int x, int y) {
    if (d[x][y].size()) return d[x][y];
    if (x == n && y == n) return vector<ll>(1, 1);
    if (!a[x][y]) return vector<ll>(1, 0);
    vector<ll> ans;
    for (int i = 0; i < 2; i++) {
        int nx = x + a[x][y] * dx[i];
        int ny = y + a[x][y] * dy[i];
        if (nx > n || ny > n || d[x][y].size()) continue;
        ans = add(ans, dp(nx, ny));
    }
    d[x][y] = ans;
    return ans;
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    vector<ll> ans = dp(1, 1);
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (i == ans.size() - 1) printf("%lld", ans[i]);
        else printf("%017lld", ans[i]);
    }
    return 0;
}
