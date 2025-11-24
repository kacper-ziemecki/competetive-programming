#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void counting_sort(vector<ll>& p, vector<ll>& c){
  ll n = p.size();
  vector<ll> cnt(n);
  for(auto el : c) cnt[el]++;
  vector<ll> p_new(n);
  vector<ll> pos(n);
  pos[0] = 0;
  for(int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1];
  for(auto el : p){
    ll i = c[el];
    p_new[pos[i]] = el;
    pos[i]++;
  }
  p = p_new;
}

void solve()
{
  string s;
  cin >> s;
  s += '$';
  ll n = s.size();
  vector<ll> p(n), c(n);

  vector<pair<char,ll>> a(n);
  for(ll i = 0; i < n; i++) a[i] = {s[i], i};
  sort(a.begin(), a.end());
  for(ll i = 0; i < n; i++) p[i] = a[i].second;

  c[p[0]] = 0;
  for(ll i = 1; i < n; i++){
    if(a[i].first == a[i-1].first){
      c[p[i]] = c[p[i-1]];
    } else{
      c[p[i]] = c[p[i-1]]+1;
    }
  }

  ll k = 0;
  while((1 << k) < n){
    for(ll i = 0; i < n; i++){
      p[i] = (p[i] - (1 << k) + n) % n;
    }
    counting_sort(p,c);

    vector<ll> c_new(n);
    c_new[p[0]] = 0; 
    for(ll i = 1; i < n; i++){
      pair<ll,ll> prev = {c[p[i-1]], c[(p[i-1]+(1 << k))%n]};
      pair<ll,ll> now = {c[p[i]], c[(p[i]+(1 << k))%n]};
      if(prev == now){
        c_new[p[i]] = c_new[p[i-1]];
      } else{
        c_new[p[i]] = c_new[p[i-1]]+1;
      }
    }
    c = c_new;
    k++;
  }

  for(ll i = 0; i < n; i++){
    cout << p[i] << ' ';
  }
  cout << endl;
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

  solve();
}