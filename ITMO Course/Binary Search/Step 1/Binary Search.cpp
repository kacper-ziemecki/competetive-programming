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

		ll l = 0; //list[l] < a
		ll r = n-1; //list[r] >= a
		ll m;
		while(l < r){
			m = (l + r)/2;
			if(list[m] < a){
				l = m+1;
			}
			else{
				r = m;
			}
		}
		if(list[r] == a){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
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