#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(ll n)
{
  vector<string> list(n);
  vector<ll> count(n,0);
  string s,napis;
  for(auto &el : list) cin >> el;
  cin >> s;
  for(ll index = 0; index < n; index++){
    napis = list[index]+'#'+s;
    ll m = napis.size();
    vector<ll> pi(m,0);
    for(ll i = 1; i < m; i++){
      ll j = pi[i-1];
      while(j > 0 && napis[i] != napis[j]) j = pi[j-1];
      if(napis[i] == napis[j]) j++;
      pi[i] = j;
      if(pi[i] == list[index].size()) count[index]++;
    }
  }
  ll mx = count[max_element(count.begin(), count.end())-count.begin()];
  cout << mx << endl;
  for(ll i = 0; i < n; i++){
    if(count[i] == mx) cout << list[i] << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  ll n;
  while(cin >> n, n != 0) solve(n); 
}