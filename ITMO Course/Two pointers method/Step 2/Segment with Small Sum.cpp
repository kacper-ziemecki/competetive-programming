#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	ll l = 0,res = 0, temp = 0;
	for(ll r = 0; r < n; r++){
		temp += list[r];
		while(temp > m){
			temp -= list[l];
			l++;
		}
		res = max(res, r - l + 1);
	}
	cout << res << endl;
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