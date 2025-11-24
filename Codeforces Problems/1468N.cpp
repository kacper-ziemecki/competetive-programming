#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll c1,c2,c3,a1,a2,a3,a4,a5;
  cin >> c1 >> c2 >> c3 >> a1 >> a2 >> a3 >> a4 >> a5;

  c1 -= a1;
  c2 -= a2;
  c3 -= a3;
  if(c1 < 0 || c2 < 0 || c3 < 0){
    cout << "NO\n";
    return;
  }
  a4 -= c1;
  a5 -= c2;
  if(max(0ll, a4) + max(0ll, a5) > c3){
    cout << "NO\n";
    return;
  }
  cout << "YES\n";

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
  while(t--) solve();
}