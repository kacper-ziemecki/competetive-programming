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

ll n,k;

void solve(){
  cin >> n >> k;
  vector<ll> lista(n);
  vector<vector<ll>> res;
  vector<bool> vis(n);
  for(int i = 0; i < n; i++){
    cin >> lista[i];
  }
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, less<>> pq_max;
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>> pq_min
  for(int i = 0; i < n; i++){
    pq_max.emplace(make_pair(lista[i], i));
    pq_min.emplace(make_pair(lista[i], i));
  }

  for(int i = 0; i < n; i++){
    ll mn = lista[sorted_lista[i].second];
    if(mn > k){
      cout << "NIE\n";
      return;
    }
    vis[sorted_lista[i].second] = true;
    // for(auto el : vis) cout << el << ' ';
    // cout << endl;
    // dbg(mn,k);
    while(!pq.empty() && vis[pq.top().second]) pq.pop();
    ll mx = (pq.empty() ? 0 : pq.top().first);
    // dbg(pq.empty());
    res.pb({sorted_lista[i].second, mn, (pq.empty() ? 0 : pq.top().second), min(mx, k-mn)});
    // dbg(mx);
    // dbg(sorted_lista[i].second,mn,pq.top().second,min(mx, k-mn));
    if(!pq.empty()) lista[pq.top().second] = max(0ll, mx-(k-mn));
    // dbg(lista[pq.top().second]);
    if(!pq.empty()) pq.emplace(make_pair(max(0ll, mx-(k-mn)), pq.top().second)); pq.pop();
  }
  cout << "TAK\n";
  for(auto sub : res){
    if(sub[1] == 0 && sub[3] == 0){
      cout << 0 << endl;
    } else if(sub[3] == 0){
      cout << 1 << ' ' << sub[0]+1 << ' ' << sub[1] << endl;
    } else{
      cout << 2 << ' ' << sub[0]+1 << ' ' << sub[1] << ' ' << sub[2]+1 << ' ' << sub[3] << endl;
    }
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