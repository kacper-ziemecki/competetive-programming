#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(vector<ll>& a, vector<ll>& b, ll k, ll m){
  for(ll i = 0; i < a.size(); i++){
    k -= max(0ll, a[i]*m-b[i]);
    if(k < 0) return false;
  }
  return true;
}

ll iterations=0;

void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  ll l=0, r=2000000001;
  while(l<r){
    ll m = (l+r+1)/2;
    if(check(a,b,k,m)) l=m;
    else r = m-1;
  }
  cout << l << endl;
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