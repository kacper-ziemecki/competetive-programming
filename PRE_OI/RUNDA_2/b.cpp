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

int n,q;
int l,r,m,k;
const int N = 1e5+1;
int lista[N];
priority_queue<int,vector<int>,greater<>> pq;
vector<int> res;
map<vector<int>, vector<int>> dp;

void solve(){
  cin >> n >> q;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < q; i++){
    cin >> l >> r >> m >> k;
    if(dp.count(vector<int>{l,r,m})){
      cout << dp[vector<int>{l,r,m}][k-1] << endl;
      continue;
    }
    res.clear();
    while(!pq.empty()) pq.pop();
    bool stopped = false;

    for(int j = l-1; j < r; j++){
      pq.emplace(lista[j]);
      if(pq.size() == m){
        res.pb(pq.top());
        pq.pop();
      }
      if(res.size() == k){
        cout << res[k-1] << endl;
        stopped = true;
        break;
      }
    }
    if(stopped) continue;
    while(!pq.empty()){
      res.pb(pq.top());
      pq.pop();
    }
    if(dp.size() < 50) dp[vector<int>{l,r,m}] = res;
    cout << res[k-1] << endl;
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