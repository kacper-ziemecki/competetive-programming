#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n;
	cin >> n;
	vector<vector<ll>> list(n, vector<ll>(0, 0));
	ll a;
	ll lim = 1;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < lim; j++){
			cin >> a;
			list[i].push_back(a);
		}
		lim *= 2;
	}
	for(ll j = 1; j < n; j++){
		for(ll i = 0; i < list[n-j].size(); i+= 2){
			list[n-j-1][i/2] += min(list[n-j][i], list[n-j][i+1]);
		}
	}
	cout << list[0][0] << endl;
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