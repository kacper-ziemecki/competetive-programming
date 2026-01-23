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

int n;
int u,v,w;
int timer;
const int N = 10000+1;
const int L = ceil(log2(N))+1;
int timein[N], timeout[N], depth[N], up[N][L];
vector<int> adj[N];

void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair())
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

  int t;
  cin >> t;
  while(t--)
  solve();
}