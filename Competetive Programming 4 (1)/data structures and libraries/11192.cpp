#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n)
{
  string text;
  cin >> text;
  ll begining = 0, ending = text.size() / n;
  for (ll i = 0; i < n; i++)
  {
    reverse(text.begin() + begining, text.begin() + ending);
    begining += text.size() / n;
    ending += text.size() / n;
  }
  cout << text << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ll n;
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;
    solve(n);
  }
}