#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,a;
  cin >> n >> a;
  string text;
  cin >> text;
  vector<ll> list;
  ll i = -1;
  for(auto el : text){
    i++;
    i %= 1000000007;
    if(el == 'a' || el == 'e' || el == 'o' || el == 'i' || el == 'u'){
      list.push_back(i);
    }
  }
  ll res = 1;
  for(ll i = a-1; i < list.size()-1; i += a){
    res *= (list[i+1] - list[i]) % 1000000007;
    res %= 1000000007;
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}