#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n+1);
  vector<pair<int, double>> B(m);

  for(int i = 1;i <=n;i++) {
    cin >> A[i];
  }
  for(int i = 0;i < m;i++) {
    cin >> B[i].first >> B[i].second;
  }

  int mismatch = -1;
  for(int i = 1; i <= n;i++) {
    if(i != A[i]) mismatch = i;
  }

  if(mismatch == -1) {
    cout << 1 << endl;
    return;
  }

  double prob = 1;
  for(int i = 0;i < m;i++) {
    if(B[i].first >= mismatch) {
      prob *= (1-B[i].second);
    }
  }

  cout << setprecision(15) << fixed << 1-prob << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
