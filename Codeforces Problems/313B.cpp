#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  cin >> text;
  vector<ll> prefix_sums(text.size(), 0);
  for(ll i = 1; i < text.size(); i++){
    prefix_sums[i] = prefix_sums[i-1] + (text[i] == text[i-1] ? 1 : 0);
  }

  ll q;
  cin >> q;
  ll l,r;
  while(q--){
    cin >> l >> r;
    l--;
    r--;
    cout << prefix_sums[r] - prefix_sums[l] << endl;
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