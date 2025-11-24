#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<string> list(m);
  for(auto &el : list) cin >> el;
  string s = list[0];
  // dbg(s);
  for(ll i = 1; i < m; i++){
    string tmp = list[i]+'#'+s;
    ll x = tmp.size();
    vector<ll> pi(x,0);
    for(ll i = 1; i < x; i++){
      ll j = pi[i-1];
      while(j > 0 && tmp[i] != tmp[j]) j = pi[j-1];
      if(tmp[i] == tmp[j]) j++;
      pi[i]=j;
    }
    // dbg(pi[x-1]);
    s += list[i].substr(pi[x-1], x-pi[x-1]);
    // dbg(s);
  }
  cout << s.size() << endl;
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

  ll t;
  cin >> t;
  while(t--)
    solve(); 
}