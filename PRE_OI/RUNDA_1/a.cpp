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

const int N = 1e5+1;
const int M = 1e5+1;
int n,m,q;
int l,r;
vector<int> grupy[M];
vector<ll> pref[M];
int lista[N];

void solve(){
  cin >> n >> m >> q; 
  for(int i = 1; i <= m; i++){
    grupy[i].clear();
    pref[i].clear();
  }
  for(int i = 0; i < n; i++){
    cin >> lista[i];
    grupy[lista[i]].pb(i);
  }
  for(int i = 1; i <= m; i++){
    for(int j = 0; j < grupy[i].size(); j++){
      pref[i].pb(grupy[i][j] + (j-1 < 0 ? 0 : pref[i][j-1]));
      // dbg(pref[i][j],grupy[i][j]);
    }
  }
  for(int i = 0; i < q; i++){
    cin >> l >> r;
    ll res=0;
    if(grupy[l].size() > grupy[r].size()) swap(l,r);
    // dbg(l,r);
    // lewo ma mniejsza grupe
    for(int j = 0; j < grupy[l].size(); j++){
      int idx = upper_bound(grupy[r].begin(), grupy[r].end(), grupy[l][j]) - grupy[r].begin();
      // dbg(idx,grupy[l][j]);
      ll suma_pref = (idx-1 < 0 ? 0 : pref[r][idx-1]);
      ll suma_suf = pref[r][pref[r].size()-1] - (idx-1 < 0 ? 0 : pref[r][idx-1]);
      int ile_przed = idx;
      int ile_po = grupy[r].size()-idx;
      // dbg(suma_pref, suma_suf);
      res += ((ile_przed*grupy[l][j])-suma_pref)+(suma_suf-(ile_po*grupy[l][j]));
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

  int t;
  cin >> t;
  while(t--)
  solve();
}