#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(string s)
{
  ll n = (int)s.size();
  vector<ll> pi(n,0);
  for(ll i = 1; i < n; i++){
    ll j = pi[i-1];
    while(j > 0 && s[i] != s[j]) j = pi[j-1];
    if(s[i] == s[j]) j++;
    pi[i]=j;
  }
  if(n%(n-pi[n-1])) cout << 1 << endl;
  else cout << n/(n-pi[n-1]) << endl;
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

  string s;
  while(cin >> s, s!=".")
    solve(s); 
}