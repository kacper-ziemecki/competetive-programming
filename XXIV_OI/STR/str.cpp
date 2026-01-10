#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
int u,v;
int res=1;
const int maxn = 5e5+1;
vector<int> adj[maxn];
int parent[maxn];
bool strajk[maxn];
int cnt[maxn];

void dfs(int u, int p){
  parent[u] = p;
  for(auto v : adj[u]){
    if(v != p) dfs(v,u);
  }
}

void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  } 
  dfs(1, 1); // ukorzeniamy drzewo na wierzcholku 1
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> u;
    // dbg(u);
    if(u > 0){
      strajk[u] = true;
      if(u != 1) cnt[parent[u]]++;
      int sasiedzi = adj[u].size();
      int sasiedzi_strajki = cnt[u];
      if(u != 1 && strajk[parent[u]]){
        // cout << "zrobilem kupe\n";
        sasiedzi_strajki++;
      }
      // dbg(sasiedzi, sasiedzi_strajki);
      if(sasiedzi == sasiedzi_strajki){
        res--;
      } else{
        res += max(0,sasiedzi - sasiedzi_strajki - 1);
      }
    } else{
      strajk[-u] = false;
      if(-u != 1) cnt[parent[-u]]--;
      int sasiedzi = adj[-u].size();
      int sasiedzi_strajki = cnt[-u];
      if(-u != 1 && strajk[parent[-u]]) sasiedzi_strajki++;
      if(sasiedzi == sasiedzi_strajki){
        res++;
      } else{
        res -= max(0, sasiedzi - sasiedzi_strajki - 1);
      }
    }

    cout << res << endl;
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