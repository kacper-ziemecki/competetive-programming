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
  int n;
  cin >> n;
  vector<int> lista(n), prefix(n), suffix(n);
  for(auto &el : lista) cin >> el;  
  for(int i = 1; i < n; i++){
    prefix[i] = prefix[i-1]+abs(lista[i]-lista[i-1]);
  }
  for(int i = n-2; i >= 0; i--){
    suffix[i] = suffix[i+1]+abs(lista[i]-lista[i+1]);
  }
  int res = prefix[n-1];
  // dbg(res);
  for(int i = 0; i < n; i++){ 
    res = min(res, (i == 0 || i == n-1 ? 0 : abs(lista[i-1]-lista[i+1]))+(i-1 < 0 ? 0 : prefix[i-1]) + (i+1 >= n ? 0 : suffix[i+1]));
    // dbg((i-1 < 0 ? 0 : prefix[i-1]),(i+1 >= n ? 0 : suffix[i+1]));
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

  int t;
  cin >> t;
  while(t--)
  solve();
}