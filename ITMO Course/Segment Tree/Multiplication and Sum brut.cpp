#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m,t,l,r,v;
const ll MOD = 1e9+7;
const ll maxn = 100001;
ll lista[maxn];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) lista[i] = 1;
  for(int i = 0; i < m; i++){
    cin >> t;
    if(t==1){
      cin >> l >> r >> v;
      for(int j = l; j < r; j++) lista[j] = (lista[j]*v) % MOD;
    } else{
      cin >> l >> r;
      ll res = 0;
      for(int j = l; j < r; j++) res = (res + lista[j]) % MOD;
      cout << res << endl;
    }
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

  solve();
}