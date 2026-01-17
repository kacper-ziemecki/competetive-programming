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
int u;
const int maxn = 1e5+1;
vector<int> adj[maxn];
int parent[maxn], cnt[maxn];

void solve(){
  cin >> n;
  parent[1] = 1;
  for(int i = 0; i < n-1; i++){
    cin >> parent[2+i];
    adj[parent[2+i]].pb(2+i);
  }
  cnt[0] = 1;
  queue<int> q1,q2;
  q1.push(1);
  int poziom = 0;
  while(true){
    poziom++;
    while(!q1.empty()){
      u = q1.front(); q1.pop();
      // dbg(u, poziom);
      for(auto v : adj[u]){
        cnt[poziom]++;
        q2.push(v);
      }
    }
    if(q2.empty()) break;
    q1 = q2;
    while(!q2.empty()) q2.pop();
  }
  int res = 0;
  for(int i = 0; i < n; i++){
    res += cnt[i] % 2;
  }
  cout << res << endl;
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