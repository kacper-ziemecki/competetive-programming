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

bool check(ll h, ll n, vector<ll>& a, vector<ll>& c, ll m){
	for(ll i = 0; i < n; i++){
		h -= ((m+c[i]-1)/c[i])*a[i];
		if(h <= 0) return true;
	}
	return false;
}


void solve()
{
	ll iter = 0; 
 	ll h,n;
 	cin >> h >> n;
 	vector<ll> a(n), c(n);
 	for(auto &el : a) cin >> el;
 	for(auto &el : c) cin >> el;

 	ll l = 0, r = 1e13;
	while(l < r){
		ll m = (l+r)/2;
		if(check(h,n,a,c,m)) r = m;
		else l = m+1;
	}
	cout << r << endl;
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