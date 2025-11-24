#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> list(n, 0), prefix(n, 0);
	for(auto &el : list) cin >> el;

	for(ll i = 0; i < n; i++){
		prefix[i] = (i > 0 ? prefix[i-1] : 0) + list[i];
	}
	map<ll, ll> mapa;
	ll res = 0;
	for(ll i = 0; i < n; i++){
		if(mapa[prefix[i] - m]){
			res = max(res, i - mapa[prefix[i] - m] + 1);
		}
		if(!mapa[prefix[i]]) mapa[prefix[i]] = i+1;
	}
	cout << res << endl;
}
	

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
//   freopen("../../output.txt", "w", stdout);
// #endif

  solve();
}