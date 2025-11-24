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
ll n,m;
vector<ll> res;
void solve()
{
	cin >> t >> s;
	n = t.size(); m = s.size();
	for(ll i = 0; i+m-1 < n; i++){
		bool flag = true;
		for(ll j = 0; j < m; j++){
			if(t[i+j] != s[j]) flag = false;
		}
		if(flag) res.pb(i);
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