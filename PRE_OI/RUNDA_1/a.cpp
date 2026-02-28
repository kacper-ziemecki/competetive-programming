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

<<<<<<< HEAD
const ll N = 1e5+1;
const ll M = 1e5+1;
ull n,m,q;
ull l,r;
vector<ull> grupy[M];
vector<ull> pref[M];
ull lista[N];
=======
const int N = 1e5+1;
const int M = 1e5+1;
int n,m,q;
int l,r;
vector<int> grupy[M];
vector<int> pref[M];
int lista[N];
>>>>>>> 53315e3229e1c2ac37a3c0fc1e503d2746a05155

void solve(){
  cin >> n >> m >> q; 
  for(ll i = 1; i <= m; i++){
    grupy[i].clear();
    pref[i].clear();
  }
  for(ll i = 0; i < n; i++){
    cin >> lista[i];
    grupy[lista[i]].pb(i);
  }
  for(ll i = 1; i <= m; i++){
    for(ll j = 0; j < grupy[i].size(); j++){
      pref[i].pb(grupy[i][j] + (j-1 < 0 ? 0 : pref[i][j-1]));
      // dbg(pref[i][j],grupy[i][j]);
    }
  }
  for(ll i = 0; i < q; i++){
    cin >> l >> r;
<<<<<<< HEAD
    ull res=0;
=======
    int res=0;
>>>>>>> 53315e3229e1c2ac37a3c0fc1e503d2746a05155
    if(grupy[l].size() > grupy[r].size()) swap(l,r);
    // dbg(l,r);
    // lewo ma mniejsza grupe
    for(ll j = 0; j < grupy[l].size(); j++){
      ll idx = upper_bound(grupy[r].begin(), grupy[r].end(), grupy[l][j]) - grupy[r].begin();
      // dbg(idx,grupy[l][j]);
<<<<<<< HEAD
      ull suma_pref = (idx-1 < 0 ? 0 : pref[r][idx-1]);
      ull suma_suf = pref[r][pref[r].size()-1] - (idx-1 < 0 ? 0 : pref[r][idx-1]);
      ull ile_przed = idx;
      ull ile_po = grupy[r].size()-idx;
=======
      int suma_pref = (idx-1 < 0 ? 0 : pref[r][idx-1]);
      int suma_suf = pref[r][pref[r].size()-1] - (idx-1 < 0 ? 0 : pref[r][idx-1]);
      int ile_przed = idx;
      int ile_po = grupy[r].size()-idx;
>>>>>>> 53315e3229e1c2ac37a3c0fc1e503d2746a05155
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