#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct DSU{
  vector<int> p,sajz;
  DSU(int n){
    p.resize(n+1);
    sajz.assign(n+1,1);
    for(int i = 0; i <= n; i++) p[i] = i;
  }
  int findSet(int a){
    return (a == p[a] ? a : p[a] = findSet(p[a]));
  }
  void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
  bool connected(int a, int b){
    return findSet(a) == findSet(b);
  }
};

int n,m;
int u,v;
int mx_size=1, cnt;

void solve(){
  cin >> n >> m;
  cnt = n;
  DSU dsu(n+1);
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    if(!dsu.connected(u,v)){
      cnt--;
      dsu.unionSet(u,v);
      mx_size = max(mx_size,dsu.sajz[dsu.findSet(u)]);
    }
    cout << cnt << ' ' << mx_size << endl;
  }
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}