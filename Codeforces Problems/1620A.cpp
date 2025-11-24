#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p(1e6, 0), s(1e6, 1);

ll find_set(ll v){
  if(p[v] == v){
    return v;
  }
  return p[v] = find_set(p[v]);
}

void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a != b){
    if(s[a] < s[b]) swap(a,b);
    p[b] = a;
    s[a] += s[b];
  }
}

void solve()
{
  string s;
  cin >> s;
  ll n = s.size();
  for(ll i = 0; i < n; i++) p[i]=i;
  for(ll i = 0; i < n; i++){
    if(s[i] == 'E'){
      union_sets(i, (i+1)%n);
    }
  }
  for(ll i = 0; i < n; i++){
    if(s[i] == 'N' && find_set(i) == find_set((i+1)%n)){
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