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

ll n,k;
const ll maxN = 101, maxK = 1e5+1;
ll lista[maxN];
bool state[maxK];

void solve()
{
  cin >> n >> k;
  for(ll i = 0; i < n; i++) cin >> lista[i];
  for(ll i = 0; i <= k; i++){
    for(ll j = 0; j < n; j++){
      if(i-lista[j] >= 0 && state[i-lista[j]] == false){
        state[i] = true;
      }
    }
  }
  if(state[k]) cout << "First\n";
  else cout << "Second\n";
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}