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
  ll n;
  string s;
  cin >> n >> s;
  map<char, char> m;
  m[s[0]] = '0';
  for(ll i = 1; i < n; i++){
    if(!m[s[i]]){
      if(m[s[i-1]] == '0') m[s[i]] = '1';
      else m[s[i]] = '0';
    }
    else if(m[s[i]] == m[s[i-1]]){
      cout << "NO\n";
      return;
    }
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