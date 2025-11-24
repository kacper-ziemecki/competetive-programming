#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n,k;
	cin >> n >> k;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	ll a;
	for(ll i = 0; i < k; i++){
		cin >> a;

		ll l = -1; //list[l] < a
		ll r = n; //list[r] >= a
		ll m;
		while(l+1 < r){
			m = (l + r)/2;
			if(list[m] < a){
				l = m;
			}
			else{
				r = m;
			}
		}
		cout << r+1 << endl;

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