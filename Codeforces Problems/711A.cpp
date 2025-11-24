#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  vector<string> list(n, " ");
  for (auto& el : list) cin >> el;
  bool flag = false;
  for (auto& el : list) {
    if (el[0] == 'O' && el[1] == 'O') {
      el[0] = '+';
      el[1] = '+';
      flag = true;
      break;
    }
    if (el[3] == 'O' && el[4] == 'O') {
      el[3] = '+';
      el[4] = '+';
      flag = true;
      break;
    }
  }
  if (!flag) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto el : list) {
    cout << el << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}