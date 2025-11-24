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
	ll suma = 0;
	ll minus = 0;
	ll plus = 0;
	for(auto &el : list){
		cin >> el;
		suma += el;
		if(el < 0) minus++;
		else plus++;
	}
	ll res = 0;
	while(minus > plus){
		minus--;
		plus++;

		res++;
	}
	if(minus&1){
		minus--;
		plus++;

		res++;
	}

	cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}