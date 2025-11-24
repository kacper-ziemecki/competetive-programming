#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  vector<int> ans(n, 0);
  for(auto &el : ans) cin >> el;
  sort(ans.begin(), ans.end());
  int res = INT_MAX;
  for(int i = 1; i < n; i++){
    res = min(res, abs(ans[i] - ans[i-1]));
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}