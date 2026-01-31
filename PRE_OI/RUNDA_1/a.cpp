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

ll n,m,k;
int u,v;
string s;
const int N = 1e3+1;
pair<int,int> adj[N];
ll dist[N];
ll ile_do_cyklu, ile_ma_cykl, wierzcholek;
int wynik, powtorzenia;

bool dfs(int u, int idx, ll cnt=0){
  if(idx == 0 && dist[u] != -1){ //mamy cykl
    ile_do_cyklu = dist[u];
    ile_ma_cykl = cnt-dist[u];
    wierzcholek = u;
    return true;
  }
  if(idx == 0) dist[u] = cnt;
  if((s[idx] == 'L') && dfs(adj[u].first, (idx+1)%m, (idx==m-1 ? cnt+1 : cnt))) return true;
  if((s[idx] == 'P') && dfs(adj[u].second, (idx+1)%m, (idx==m-1 ? cnt+1 : cnt))) return true;
  return false;
}
void powtarzaj(int u, int idx, ll cnt=0){
  if((idx == 0) && (cnt == powtorzenia)){
    wynik = u;
    return;
  }
  if(s[idx] == 'L') powtarzaj(adj[u].first, (idx+1)%m, (idx==m-1 ? cnt+1 : cnt));
  if(s[idx] == 'P') powtarzaj(adj[u].second, (idx+1)%m, (idx==m-1 ? cnt+1 : cnt));
}

void solve(){
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) dist[i] = -1;
  for(int i = 1; i <= n; i++){
    cin >> u >> v;
    adj[i] = make_pair(u,v);
  }
  cin >> s;
  dfs(1,0);
  // dbg(ile_do_cyklu, ile_ma_cykl, wierzcholek);
  if(ile_do_cyklu >= k){
    powtorzenia = k;
    // dbg(powtorzenia);
    powtarzaj(1,0);
  } else{
    k -= ile_do_cyklu;
    k = k % ile_ma_cykl;
    powtorzenia = k;
    // dbg(powtorzenia);
    powtarzaj(wierzcholek,0);
  }
  cout << wynik << endl;
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