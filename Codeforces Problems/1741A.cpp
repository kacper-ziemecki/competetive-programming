#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string one, two;
  cin >> one >> two;
  if (one.back() == 'M' && two.back() == 'S') {
    cout << ">\n";
  }
  else if (one.back() == 'M' && two.back() == 'L') {
    cout << "<\n";
  }
  else if (one.back() == 'S' && two.back() == 'M') {
    cout << "<\n";
  }
  else if (one.back() == 'S' && two.back() == 'L') {
    cout << "<\n";
  }
  else if (one.back() == 'L' && two.back() == 'M') {
    cout << ">\n";
  }
  else if (one.back() == 'L' && two.back() == 'S') {
    cout << ">\n";
  }
  else if (one.back() == 'S' && two.back() == 'S') {
    if (one.size() > two.size()) {
      cout << "<\n";
    }
    else if (one.size() < two.size()) {
      cout << ">\n";
    }
    else {
      cout << "=\n";
    }
  }
  else if (one.back() == 'L' && two.back() == 'L') {
    if (one.size() > two.size()) {
      cout << ">\n";
    }
    else if (one.size() < two.size()) {
      cout << "<\n";
    }
    else {
      cout << "=\n";
    }
  }
  else if (one.back() == 'M' && two.back() == 'M') {
    cout << "=\n";
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

  ll t;
  cin >> t;
  while (t--) solve();

}