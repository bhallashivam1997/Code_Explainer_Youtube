#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005], A[1005], B[1005], n, m;

int cost(int i, int j) {
  if(i == -1 && j == -1) return 0;
  if(i == -1) return j+1;
  if(j == -1) return i+1;

  if(dp[i][j] != 0) return dp[i][j];

  int u = cost(i-1, j) + 1;
  int v = cost(i, j-1) + 1;
  int w = cost(i-1, j-1) + (A[i] != B[j]);
  return dp[i][j] = min(u, min(v, w));
}

void solve() {
  cin >> n >> m;
  for(int i = 0;i < n;i++) cin >> A[i];
  for(int i = 0;i < m;i++) cin >> B[i];
  cout << cost(n-1, m-1) << endl;
}

int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
