#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> p, _size;
vector<vector<ll>> alphabet;

ll find_set(ll a){
  return (p[a] == a ? a : p[a] = find_set(p[a]));
}

void add_letter(char c, ll a){
  alphabet[a][c-'a']++;
  _size[a]++;
}

void union_sets(ll a, ll b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;
  if(_size[a] < _size[b]) swap(a,b);
  p[b] = a;
  _size[a] += _size[b];
  _size[b] = 0;
  for(ll i = 0; i < 'z'-'a'+1; i++){
    alphabet[a][i] += alphabet[b][i];
    alphabet[b][i] = 0;
  }
}

void solve()
{
  ll n,k;
  string s;
  cin >> n >> k >> s;
  p.assign(k, 0); _size.assign(k, 0); alphabet.assign(k, vector<ll>('z'-'a'+1, 0));
  for(ll i = 0; i < k; i++) p[i]=i;
  for(ll i = 0; i < n; i++) add_letter(s[i], i % k);
  for(ll i = 0; i < n; i++) union_sets(i%k, (n-i-1)%k);
  ll res = 0;
  for(ll i = 0; i < k; i++){
    ll mx = 0;
    for(auto el : alphabet[i]) mx = max(mx, el);
    res += _size[i]-mx;
  }
  cout << res << endl;
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