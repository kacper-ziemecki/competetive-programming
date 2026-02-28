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

const ll N = 1e5+1;
vector<pair<ll,ll>> adj[N];
vector<vector<ll>> adj2[N];
vector<ll> cofanie,suma_pref;
ll mx_sciezka[N];
ll n,q,pi;
ll u,v,w;
ll suma, res;

ll oblicz_mx_sciezka(ll u, ll p){
  mx_sciezka[u] = 0;
  for(auto edge : adj[u]){
    ll v = edge.first;
    ll w = edge.second;
    if(v != p){
      suma += w;
      mx_sciezka[u] = max(mx_sciezka[u], w+oblicz_mx_sciezka(v,u));
      adj2[u].pb(vector<ll>{mx_sciezka[v],w,v});
    }
  }
  return mx_sciezka[u];
}

void oblicz_cofanie(ll u, ll suma=0){
  if(adj2[u].empty()){
    cofanie.pb(suma);
  }
  for(ll i = 0; i < adj2[u].size(); i++){
    oblicz_cofanie(adj2[u][i][2], suma+adj2[u][i][1]);
  }
}

void solve(){
  cin >> n;
  if(n == 1){
    cin >> q;
    for(int i = 0; i < q; i++){
      cin >> pi;
      cout << 0 << endl;
    }
    return;
  }
  cofanie.clear();
  suma_pref.clear();
  suma = 0;
  for(ll i = 0; i <= n; i++){
    adj[i].clear();
    adj2[i].clear();
    mx_sciezka[i]=0;
  }

  for(ll i = 0; i < n-1; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
  }
  oblicz_mx_sciezka(1,1);
  for(ll i = 1; i <= n; i++){
    sort(adj2[i].begin(), adj2[i].end(),greater<>());
  }
  oblicz_cofanie(1);
  cofanie.erase(cofanie.begin());
  sort(cofanie.begin(),cofanie.end(),greater<>());
  suma_pref.pb(cofanie.front());
  for(ll i = 1; i < cofanie.size(); i++){
    suma_pref.pb(cofanie[i]+suma_pref[i-1]);
  }
  cin >> q;
  for(ll i = 0; i < q; i++){
    cin >> pi;
    res = suma;
    ll l = 0, r = cofanie.size()-1;
    while(l < r){
      ll mid = (l+r+1)/2;
      if(cofanie[mid] >= pi) l = mid;
      else r = mid-1;
    }
    if(cofanie[l] >= pi) l++;
    res += l*pi + suma_pref.back()-(l-1 < 0 ? 0 : suma_pref[l-1]);
    cout << res << endl;
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