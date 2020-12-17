#include <bits/stdc++.h>
using namespace std;

int find_range(vector<int> &A, vector<int> &B, int &n) {
  int ans = 0, lo = 0, hi = n-1;
  while (lo <= hi) {
    int k = (lo+hi)/2;
    bool possible = true;
    for(int i = 0;i <= k;i++) {
      if(A[i] > B[n-1-k+i]) possible = false;
    }
    if(possible) {
      ans = k+1;
      lo = k+1;
    } else {
      hi = k-1;
    }
  }
  return ans;
}

void solve() {
  int n, num;cin>>n;
  vector<int> H(2*n+1, 0);
  for(int i = 0;i < n;i++) {
    cin >> num;
    H[num] = 1;
  }
  vector<int> A, B;
  for(int i = 1;i <= 2*n;i++) {
    if(H[i] == 0) A.push_back(i);
    else B.push_back(i);
  }

  int n1 = find_range(A, B, n);
  int n2 = n - find_range(B, A, n);

  cout << max(0, n1-n2+1) << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
