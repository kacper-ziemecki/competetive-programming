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

ll n,m;
char c;
ll x,y,z,s,a,x1,x2;
const ll maxn = 300000+1;
ll suma[maxn];
pair<ll,ll> lista[maxn];



void solve(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> c;
    if(c == 'P'){
      cin >> x >> s >> a;
      lista[x] = make_pair(s,a);
      for(int j = 1; j <= n; j++) suma[j] += max(0ll, s-abs(x-j)*a);
    } else if(c == 'U'){
      cin >> x;
      s = lista[x].first;
      a = lista[x].second;
      for(int j = 1; j <= n; j++) suma[j] -= max(0ll, s-abs(x-j)*a);
    } else{
      cin >> x1 >> x2;
      ll res = 0;
      for(int j = x1; j <= x2; j++) res += suma[j];
      cout << res/(x2-x1+1) << endl;
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