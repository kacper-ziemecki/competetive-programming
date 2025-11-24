	#include <bits/stdc++.h>
	using namespace std;
	#define endl "\n"
	#define ll long long
	#define ld long double



	void solve()
	{
		ll n;
		cin >> n;
		vector<ll> list(n, 0);
		for(auto &el : list) cin >> el;
		sort(list.begin(), list.end());
		ll k;
		cin >> k;
		ll a,b;
		for(ll i = 0; i < k; i++){
			cin >> a >> b;
			ll first = lower_bound(list.begin(), list.end(), a) - list.begin();
			ll second = upper_bound(list.begin(), list.end(), b) - list.begin();
			cout << second - first << " ";
		}
	}

	int main()
	{

	  ios_base::sync_with_stdio(0);
	  cin.tie(0);
	  cout.tie(0);

	#ifndef ONLINE_JUDGE
	  freopen("../../../../input.txt", "r", stdin);
	  freopen("../../../../output.txt", "w", stdout);
	#endif

	  solve();
	}