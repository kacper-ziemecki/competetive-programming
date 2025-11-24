#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
struct segtree {
  int size;
  vector<long long> operations;
  vector<long long> mins;

  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    opertaions.assign(2*size, 0ll);
    mins.assign(2*size, 0ll);
  }

  void add(int l, int r, int v, int x, int lx, int rx){
    if(lx >= l || l >= rx) return;
    if(lx >= l && rx <= r){
      opertaions[x] += v;
      mins[x] += v;
      return;
    }
    int m = (lx + rx) / 2;
    add(l, r, v, 2*x+1, lx, m);
    add(l, r, v, 2*x+2, m, rx);
    mins[x] = min(mins[2*x+1], mins[2*x+2])
  }

  void add(int l, int r, int v){
    add(l, r, v, 0, 0, size);
  }

  long long get(int i, int x, int lx, int rx){
    if(rx - lx == 1){
      return opertaions[x];
    }
    int m = (lx + rx) / 2;
    long long res;
    if(i < m){
      res = get(i, 2 * x + 1, lx, m);
    } else{
      res = get(i, 2 * x + 2, m, rx);
    }
    return res;
  }
}
 
void solve(){
  ll n,m,a,b,c,d;
  cin >> n >> m;
  Segtree tree(n);
  for(ll i = 0; i < m; i++){
    cin >> a;
    if(a == 1){
      cin >> b >> c >> d;
      tree.set(b, c, d);
    } else{
      cin >> b >> c;
      cout << tree.get(b,c) << endl;
    }
    // for(auto el : tree.mn) cout << el << " ";
    // cout << endl;
    // for(auto el : tree.lazy) cout << el << " ";
    // cout << endl;
  }
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