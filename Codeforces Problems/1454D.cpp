#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> primes;
bool vis[100001];

void solve(){
  ll n;
  cin >> n;
  map<ll,ll> mp;
  for(auto el : primes){
    while(n%el == 0){
      mp[el]++;
      n /= el;
    }
  }
  if(n > 1){
    mp[n]++;
  }
  pair<ll,ll> mx{0,0};
  for(auto el : mp){
    if(mx.second < el.second) mx = el;
  }
  vector<ll> res(mx.second, mx.first);
  ll rest=1;
  for(auto el : mp){
    if(el.first != mx.first){
      rest *= pow(el.first,el.second);
    }
  }
  res.back() *= rest;
  cout << res.size() << endl;
  for(auto el : res) cout << el << " ";
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
  
  for(ll i = 2; i < 100001; i++){
    if(!vis[i]){
      primes.push_back(i);
      for(ll j = i*i; j < 100001; j+=i) vis[j]=true;
    }
  }
  ll t;
  cin >> t;
  while(t--)
  solve();
  
}