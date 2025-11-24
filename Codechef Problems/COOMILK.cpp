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
  for(auto &el : list) cin >> el;
  for(ll i = 1; i < n; i++){
    if(list[i-1] == "cookie" && list[i] == "cookie"){
      cout << "NO\n";
      return;
    }
  }
  if(list.back() == "cookie"){
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
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--) solve();
}