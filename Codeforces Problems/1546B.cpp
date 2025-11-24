#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<string> a(n), b(n-1);
  vector<ll> alphabet;
  string res(m, '-');
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  // for(auto el : a) cout << el << " ";
  // cout << endl;
  // for(auto el : b) cout << el << " ";
  // cout << endl; 
  for(ll i = 0; i < m; i++){
    alphabet.assign('z'-'a'+1,0);
    for(ll j = 0; j < n; j++) alphabet[a[j][i]-'a']++;
    for(ll j = 0; j < n-1; j++) alphabet[b[j][i]-'a']--;
    for(ll j = 0; j < alphabet.size(); j++){
      // dbg(j, char(j+'a'), alphabet[j]);
      if(alphabet[j] == 1) res[i] = char(j+'a');
    }
    // cout << endl;
  }
  cout << res << endl;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  ll t;
  cin >> t;
  while(t--)
  solve();
}