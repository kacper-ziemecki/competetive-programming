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

int n,q,p,a,b;
int timer = 0;
const int N = 2e5+1;
const int L = ceil(log2(N))+1;
vector<int> adj[N];
int timein[N],timeout[N], dp[N][L];

void precompute(int u,int p){
  timein[u] = timer++;
  dp[u][0] = p;
  for(int i = 1; i < L; i++) dp[u][i] = dp[dp[u][i-1]][i-1];
  for(auto v : adj[u]) precompute(v,u);
  timeout[u] = timer++;
}
bool isAncestor(int a, int b){
  if(timein[a] <= timein[b] && timeout[b] <= timeout[a]) return true;
  return false;
}
int lca(int a, int b){
  if(isAncestor(a,b)){
    return a;
  }
  if(isAncestor(b,a)){
    return b;
  }
  for(int i = L-1; i >= 0; i--){
    if(!isAncestor(dp[a][i], b)) a = dp[a][i];
  }
  return dp[a][0];
}

void solve(){
  cin >> n >> q;
  for(int u = 2; u <= n; u++){
    cin >> p;
    adj[p].pb(u);
  }
  precompute(1,1);
  for(int i = 0; i < q; i++){
    cin >> a >> b;
    cout << lca(a,b) << endl;
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