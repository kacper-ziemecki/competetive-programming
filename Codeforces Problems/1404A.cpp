#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
	ll n,k;
  string s;
  cin >> n >> k >> s;
  s += '$';
  vector<ll> pref1(n), pref0(n);
  pref1[0] = (s[0]=='1');
  pref0[0] = (s[0]=='0');
  for(ll i = 1; i < n; i++){
    pref1[i] = pref1[i-1] + (s[i] == '1');
    pref0[i] = pref0[i-1] + (s[i] == '0');
  }
  bool one = true, zero = true;
  for(ll i = 1; i < n-k+1; i++){
    ll cur1 = pref1[i+k-1]-(i-1>=0?pref1[i-1] : 0);
    ll prev1 = pref1[i+k-2]-(i-2>=0?pref1[i-2] : 0);
    dbg(prev1, cur1, i, k, s[i+k-1], s[i-1]);
    if(cur1 > k/2 || prev1 > k/2){ cout << "NO\n"; return; }
    if(cur1 < prev1 && s[i+k-1] != '?'){ cout << "NO\n"; return; }
    else if(cur1 < prev1 && s[i+k-1] == '?') s[i+k-1] = '1';
    else if(cur1 > prev1 && s[i-1] != '?'){ cout << "NO\n"; return; }
    else if(cur1 > prev1 && s[i-1] == '?') s[i-1] = '1';

    ll cur0 = pref0[i+k-1]-(i-1>=0?pref0[i-1] : 0);
    ll prev0 = pref0[i+k-2]-(i-2>=0?pref0[i-2] : 0);
    dbg(prev0, cur0, i);
    if(cur0 > k/2 || prev0 > k/2){ cout << "NO\n"; return; }
    if(cur0 < prev0 && s[i+k-1] != '?'){ cout << "NO\n"; return; }
    else if(cur0 < prev0 && s[i+k-1] == '?') s[i+k-1] = '0';
    else if(cur0 > prev0 && s[i-1] != '?'){ cout << "NO\n"; return; }
    else if(cur0 > prev0 && s[i-1] == '?') s[i-1] = '0';
    dbg(s);
  }

  ll a = 0, b = 0;
  for(ll i = 0; i < k; i++){ a += s[i] == '1'; b += s[i] == '?'; }
  for(ll i = 0; i+k-1 < n; i++){
    dbg(i,a,b);
    if(a > k/2 || a+b < k/2){ cout << "NO\n"; return; }
    a -= s[i] == '1';
    b -= s[i] == '?';
    a += s[i+k] == '1';
    b += s[i+k] == '?';
  }
  cout << "YES\n";
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--)
  solve();
}