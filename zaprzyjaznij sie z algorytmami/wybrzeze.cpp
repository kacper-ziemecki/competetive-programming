#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n,k;
	cin >> n >> k;
	vector<ll> dp(n, 0);
	map<ll, vector<ll>> mapa;
	ll temp;
	for(ll i = 0; i < n; i++){
		cin >> temp;
		if(temp != -1) mapa[temp].push_back(i);
	}
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}