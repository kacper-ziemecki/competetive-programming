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

string s,t;
vector<ll> res, pi;

void solve()
{
	cin >> t >> s;
  string a = s + '#' + t;
  ll n = a.size();
  pi.resize(n);
  pi[0] = 0;
  for(ll i = 1; i < n; i++){
    ll j = pi[i-1];
    while(j != 0 && a[j] != a[i]) j = pi[j-1];
    if(a[j] == a[i]) j++;
    pi[i] = j;
    if(pi[i] == s.size()) res.pb(i-2*s.size());
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