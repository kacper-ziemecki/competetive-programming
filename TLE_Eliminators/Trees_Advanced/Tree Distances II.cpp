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

int n;
int u,v;
const int N = 2e5+1;
vector<int> adj[N];
ll subtree_size[N], ans[N];

void calc_first_ans(int u, int p){
  subtree_size[u] = 1;
  for(auto v : adj[u]){
    if(v != p){
      calc_first_ans(v,u);
      subtree_size[u] += subtree_size[v];
      ans[u] += ans[v] + subtree_size[v];
    }
  }
}

void calc_every_ans(int u, int p, ll answer){
  ans[u] = answer;
  for(auto v : adj[u]){
    if(v != p){
      // dbg(u,v);
      // dbg(ans[v], answer, subtree_size[v], n);
      answer = ans[v] + (ans[u] - (ans[v]+subtree_size[v]) + (n-subtree_size[v]));
      calc_every_ans(v,u,answer);
    }
  }
}
void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  calc_first_ans(1,1);
  calc_every_ans(1,1,ans[1]);
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
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