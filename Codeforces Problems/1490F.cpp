#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll check(map<ll,ll>& mp, ll m){
	ll res = 0;
	for(auto el : mp){
		if(el.second < m) res += el.second;
		else res += el.second-m;
	}
	return res;
}

void solve()
{
	ll n;
	cin >> n;
	vector<ll> list(n);
	for(auto &el : list) cin >> el;
	map<ll,ll> mp;
	ll mx=0;
	for(auto el : list){
		mp[el]++;
		mx = max(mx, mp[el]);
	}
	for(auto el : mp){
		cout << el.first << "->" << el.second << endl;
	}
	ll l = 0, r = mx;
	ll iter = 0;
	while(l < r){
		if(iter++ > 100) break;
		ll m1 = l + (r-l+2)/3;
		ll m2 = l + ((r-l)*2/3);
		dbg(l,m1,m2,r, check(mp,m1), check(mp,m2));
		if(check(mp,m1) < check(mp,m2)) r = m2;
		else if(check(mp,m1) >= check(mp,m2)) l = m1;
	}
	dbg(l,r,check(mp,l),check(mp,r));
	cout << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--)
  solve();
}