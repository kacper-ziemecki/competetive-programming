#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll int
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

string s,t;
ll n,m;
const ll maxN = 5e4+1, p1 = 100057, p2 = 254887, MOD = 1e9+7;
ll hashT1[maxN], hashS1, hashT2[maxN], hashS2, powers1[maxN], powers2[maxN];
vector<ll> res;

void solve()
{
  cin >> t >> s;
  n = t.size(); m = s.size();

  ll curP = 1;
  for(ll i = 0; i <= n; i++){
    powers1[i] = curP;
    curP = (curP * p1) % MOD;
  }

  curP = 1;
  for(ll i = 0; i <= n; i++){
    powers2[i] = curP;
    curP = (curP * p2) % MOD;
  }

  for(ll i = 0; i < m; i++) hashS1 = (hashS1 + (s[i]-'a'+1)*powers1[i]) % MOD;
  for(ll i = 0; i < n; i++) hashT1[i+1] = (hashT1[i] + (t[i]-'a'+1)*powers1[i]) % MOD;

  for(ll i = 0; i < m; i++) hashS2 = (hashS2 + (s[i]-'a'+1)*powers2[i]) % MOD;
  for(ll i = 0; i < n; i++) hashT2[i+1] = (hashT2[i] + (t[i]-'a'+1)*powers2[i]) % MOD;

  for(ll i = 0; i+m-1 < n; i++){
    ll curHashT1 = (hashT1[i+m]-hashT1[i]+MOD)%MOD;
    ll curHashT2 = (hashT2[i+m]-hashT2[i]+MOD)%MOD;
    // dbg(i, curHashT, (hashS * powers[i]) % MOD);
    if((curHashT1 == (hashS1 * powers1[i]) % MOD) && (curHashT2 == (hashS2 * powers2[i]) % MOD)){
      bool flag = true;
      for(ll j = 0; j < m; j++){
        if(s[j] != t[i+j]){
          flag = false;
          break;
        }
      }
      if(flag) res.pb(i);
    }
  }
  for(auto el : res) cout << el << " ";
  cout << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}