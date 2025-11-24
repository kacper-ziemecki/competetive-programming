#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

class Segtree{
public:
  ll size;
  vector<ll> sums;
  Segtree(ll n){
    size = 1;
    while(size < n) size <<= 1;
    sums.assign(2*size, 0ll);
  }
  void set(ll i, ll v, ll x, ll lx, ll rx){
    if(rx-lx==1){
      sums[x]=v;
      return;
    }
  }
};


void solve(){
  
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

  solve();
}