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




void solve(){
  ll n,x=LLONG_MIN,prefix=0;
  cin >> n;
  vector<ll> lista(n),suffix(n);
  for(auto &el : lista) cin >> el;
  suffix[n-1] = -lista[n-1];
  for(int i = n-2; i >= 0; i--){
    suffix[i] = suffix[i+1]-lista[i];
  }
  for(int i = 0; i < n; i++){
    x = max(x, prefix+(i+1 < n ? suffix[i+1] : 0));
    if(i == 0) prefix += lista[i];
    else prefix += abs(lista[i]);
  }
  cout << x << endl;
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